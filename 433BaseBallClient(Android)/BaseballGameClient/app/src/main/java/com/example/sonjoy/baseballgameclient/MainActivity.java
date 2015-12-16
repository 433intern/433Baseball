package com.example.sonjoy.baseballgameclient;

import android.app.Activity;
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

import com.example.sonjoy.baseballgameclient.Common.PlayerStatus;
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

    private Socket mLoginSocket;
    private OutputStream outStream;
    private InputStream inputStream;

    private final String realLocalIP = new String("10.100.58.3");

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        loginTaskSocket = new LoginClientSocket();
        loginTaskSocket.execute();

        Toast.makeText(this, "onCreate() 호출", Toast.LENGTH_SHORT).show();
    }

    @Override
    protected void onResume()
    {
        super.onResume();
        Toast.makeText(this, "onResume() 호출", Toast.LENGTH_SHORT).show();
    }


    public void loginBtnClicked(View v)
    {
        EditText idEdit = (EditText)findViewById(R.id.LOGIN_ID_EDIT);
        EditText passwordEdit = (EditText)findViewById(R.id.LOGIN_PASSWORD_EDIT);

        id = idEdit.getText().toString();
        password = passwordEdit.getText().toString();

        new Thread(new Runnable() {
            @Override
            public void run() {
                {
                    LoginMessage.CLS_login_request payload = LoginMessage.CLS_login_request.newBuilder()
                            .setId(id)
                            .setPassword(password)
                            .build();

                    LoginMessage.PacketHeader header = LoginMessage.PacketHeader.newBuilder()
                            .setType(LoginMessage.PacketType.CLS_LOGIN_REQUEST_VALUE)
                            .setSize(payload.getSerializedSize())
                            .build();

                    BaseballApp.Instance().sendUnionPacket(outStream, header.toByteArray(), payload.toByteArray());
                }
            }
        }).start();

    }

    public void accountCreateBtnClicked(View v)
    {
        Intent intent = new Intent(MainActivity.this, AccountCreateActivity.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_SINGLE_TOP);
        startActivity(intent);
    }

    public class LoginClientSocket extends AsyncTask<Void, String, Void>
    {
        private String LOGIN_SERVER_IP = "10.100.58.3";
        private int LOGIN_SERVER_PORT = 9001;

        private final int HEADER_SIZE = 10;

        private byte[] rcvHeaderBuf = new byte[HEADER_SIZE];
        private byte[] rcvDataBuf;

        private boolean isLoginSuccess;

        @Override
        protected void onPreExecute()
        {
            super.onPreExecute();
        }

        @Override
        protected void onProgressUpdate(String... progress)
        {
            if (progress[0].equals("LOGIN_CONNECTION_SUCCESS"))
            {
                Toast.makeText(MainActivity.this, "Login Success", Toast.LENGTH_SHORT).show();
            }
            else if(progress[0].equals("LOGIN_CONNECTION_FAILED"))
            {
                Toast.makeText(MainActivity.this, "Login Failed", Toast.LENGTH_SHORT).show();
            }
            else if (progress[0].equals("LOGIN_FAILED"))
            {
                Toast.makeText(MainActivity.this, "Login Failed", Toast.LENGTH_SHORT).show();
            }
        }

        @Override
        protected Void doInBackground(Void... parmas)
        {
            try {
                InetAddress serverAddr = InetAddress.getByName(LOGIN_SERVER_IP);
                mLoginSocket = new Socket(serverAddr, LOGIN_SERVER_PORT);
                BaseballApp.Instance().setRefLoginSocket(mLoginSocket);

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
                        if (bytesRead == -1) mLoginSocket.close();

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

        public void RecvProcess(byte[] buf, int type)
        {
            switch(type)
            {
                case LoginMessage.PacketType.LSC_LOGIN_RESULT_VALUE:

                    try {
                        LoginMessage.LSC_login_result pkt = LoginMessage.LSC_login_result.parseFrom(buf);

                        if (pkt.getFailsignal() == LoginMessage.FailSignal.UNKNOWN) {
                            isLoginSuccess = true;

                            String realIP = new String(pkt.getIp());

                            if(realIP.equals("127.0.0.1"))
                                realIP = new String(realLocalIP);

                            PlayerStatus status = new PlayerStatus();
                            status.winCount = pkt.getWinCnt();
                            status.loseCount = pkt.getLoseCnt();

                            BaseballApp.Instance().initMyPlayer(id, password, pkt.getSecurityCode(), status);
                            BaseballApp.Instance().GameServerConnection(realIP, pkt.getPort());

                        } else {
                            publishProgress("LOGIN_FAILED");
                            isLoginSuccess = false;
                        }
                    } catch (InvalidProtocolBufferException e) {
                        e.printStackTrace();
                    }


                    break;

                case LoginMessage.PacketType.LSC_ACCOUNT_CREATE_RESULT_VALUE:
                    try {
                        LoginMessage.LSC_account_create_result pkt = LoginMessage.LSC_account_create_result.parseFrom(buf);
                        BaseballApp.Instance().setSecurityCode(pkt.getSecurityCode());

                        if(pkt.getFailSignal() == LoginMessage.FailSignal.UNKNOWN)
                        {
                            BaseballApp.Instance().setAccountCreateSuccess(true);
                        }
                        else
                        {
                            BaseballApp.Instance().setIsAccountRepeatCreate(true);
                        }

                    } catch (InvalidProtocolBufferException e) {
                        e.printStackTrace();
                    }

                    break;
            }
        }
        @Override
        protected void onPostExecute(Void result)
        {
            super.onPostExecute(result);

            // Lobby로 이동
            Intent intent = new Intent(MainActivity.this, LobbyActivity.class);
            intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TASK | Intent.FLAG_ACTIVITY_NEW_TASK);
            startActivity(intent);


        }

    }


}


