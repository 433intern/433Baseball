package com.example.sonjoy.baseballgameclient;

import android.app.ActivityManager;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.example.sonjoy.baseballgameclient.Player.Player;
import com.example.sonjoy.baseballgameclient.SubActivity.AccountCreateActivity;
import com.example.sonjoy.baseballgameclient.SubActivity.LobbyActivity;
import com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration;
import com.example.sonjoy.baseballgameclient.protocol.LoginMessage;
import com.google.protobuf.InvalidProtocolBufferException;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private LoginClientSocket loginTaskSocket;

    private String id;
    private String password;

    private Socket mLoginSocket = null;

    private OutputStream outStream;
    private InputStream inputStream;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        loginTaskSocket = new LoginClientSocket();
        loginTaskSocket.execute();

        Toast.makeText(this, "onCreate() 호출", Toast.LENGTH_SHORT).show();
    }

    @Override
    protected void onResume(){
        super.onResume();
        Toast.makeText(this, "onResume() 호출", Toast.LENGTH_SHORT).show();
    }


    public void loginBtnClicked(View v){
        EditText idEdit = (EditText)findViewById(R.id.LOGIN_ID_EDIT);
        EditText passwordEdit = (EditText)findViewById(R.id.LOGIN_PASSWORD_EDIT);

        id = idEdit.toString();
        password = passwordEdit.toString();

        new Thread(new Runnable() {

            @Override
            public void run() {
                if(mLoginSocket != null)
                {
                    LoginMessage.CLS_login_request payload = LoginMessage.CLS_login_request.newBuilder()
                            .setId(id)
                            .setPassword(password)
                            .build();

                    LoginMessage.PacketHeader header = LoginMessage.PacketHeader.newBuilder()
                            .setSize(payload.getSerializedSize())
                            .setType(LoginMessage.PacketType.CLS_LOGIN_REQUEST)
                            .build();

                    try {
                        outStream.write(header.toByteArray());
                        outStream.write(payload.toByteArray());
                        outStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }

            }
        });

        Intent intent = new Intent(this, LobbyActivity.class);
        intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TASK | Intent.FLAG_ACTIVITY_NEW_TASK);
        intent.putExtra("ID",idEdit.getText());
        intent.putExtra("PASSWORD",passwordEdit.getText());
        startActivity(intent);
    }

    public void accountCreateBtnClicked(View v){

        Intent intent = new Intent(MainActivity.this, AccountCreateActivity.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_SINGLE_TOP);
        startActivity(intent);

    }

    public class LoginClientSocket extends AsyncTask {



        private String LOGIN_SERVER_IP = "127.0.0.1";
        private int LOGIN_SERVER_PORT = 9000;

        private final int HEADER_SIZE = 4;

        private byte[] rcvHeaderBuf = new byte[HEADER_SIZE];
        private byte[] rcvDataBuf;

        private boolean isLoginSuccess;

        @Override
        protected void onPreExecute() {
            super.onPreExecute();
        }

        @Override
        protected Object doInBackground(Object... parmas) {
            try {
                InetAddress serverAddr = InetAddress.getByName(LOGIN_SERVER_IP);
                mLoginSocket = new Socket(serverAddr, LOGIN_SERVER_PORT);

                outStream = mLoginSocket.getOutputStream();
                inputStream = mLoginSocket.getInputStream();

                rcvDataBuf = null;
                isLoginSuccess = false;

            } catch (UnknownHostException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }

            int bytesRead = 0;

            if (mLoginSocket != null)
            {
                while (!isLoginSuccess)
                {
                    try {
                        bytesRead = inputStream.read(rcvHeaderBuf);

                        if (bytesRead == 0) break;

                        if (rcvHeaderBuf != null) {
                            LoginMessage.PacketHeader header = LoginMessage.PacketHeader.parseFrom(rcvHeaderBuf);

                            rcvDataBuf = new byte[header.getSize()];
                            bytesRead = inputStream.read(rcvDataBuf);

                            if (bytesRead == 0) break;

                            RecvProcess(rcvDataBuf, header.getType());
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }

                try {
                    mLoginSocket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return null;
        }

        public void RecvProcess(byte[] buf, LoginMessage.PacketType type){

            switch(type)
            {
                case LSC_LOGIN_RESULT:

                    try {
                        LoginMessage.LSC_login_result pkt = LoginMessage.LSC_login_result.parseFrom(buf);

                        if(pkt.getFailsignal() == LoginMessage.FailSignal.UNKNOWN)
                        {
                            isLoginSuccess = true;
                            Toast.makeText(MainActivity.this, "Login 성공", Toast.LENGTH_SHORT).show();
                        }
                        else
                        {
                            Toast.makeText(MainActivity.this, "Login 실패", Toast.LENGTH_SHORT).show();
                        }
                    } catch (InvalidProtocolBufferException e) {
                        e.printStackTrace();
                    }


                    break;

                case LSC_ACCOUNT_CREATE_RESULT:
                    break;
            }
        }

        @Override
        protected void onPostExecute(Object result) {
            super.onPostExecute(result);



        }

    }


}


