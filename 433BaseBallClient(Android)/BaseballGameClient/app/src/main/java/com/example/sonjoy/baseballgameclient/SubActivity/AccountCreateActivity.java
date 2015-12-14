package com.example.sonjoy.baseballgameclient.SubActivity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.example.sonjoy.baseballgameclient.BaseballApp;
import com.example.sonjoy.baseballgameclient.MainActivity;
import com.example.sonjoy.baseballgameclient.R;
import com.example.sonjoy.baseballgameclient.protocol.LoginMessage;

import java.io.IOException;
import java.io.OutputStream;
import java.net.Socket;

/**
 * Created by Sonjoy on 2015-12-09.
 */
public class AccountCreateActivity extends Activity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_account_create);
        Toast.makeText(this, "onCreate() 호출", Toast.LENGTH_SHORT).show();
    }

    public void accountCreateBtnClicked(View v)
    {
        EditText idEdit = (EditText)findViewById(R.id.ACCOUNT_ID_EDIT);
        EditText passwordEdit = (EditText)findViewById(R.id.ACCOUNT_PASSWORD_EDIT);

        final String id = idEdit.getText().toString();
        final String password = passwordEdit.getText().toString();


        new Thread(new Runnable() {
            @Override
            public void run() {
                {
                    LoginMessage.CLS_account_create payload = LoginMessage.CLS_account_create.newBuilder()
                            .setId(id)
                            .setPassword(password)
                            .build();

                    LoginMessage.PacketHeader header = LoginMessage.PacketHeader.newBuilder()
                            .setType(LoginMessage.PacketType.CLS_ACCOUNT_CREATE_VALUE)
                            .setSize(payload.getSerializedSize())
                            .build();

                    try {
                        Socket refSocket = BaseballApp.Instance().getRefLoginSocket();

                        OutputStream tempOutStream = null;
                        if(refSocket != null)
                            tempOutStream = refSocket.getOutputStream();
                        BaseballApp.Instance().sendUnionPacket(tempOutStream, header.toByteArray(), payload.toByteArray());

                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
        }).start();


        Intent intent = new Intent(AccountCreateActivity.this, MainActivity.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_SINGLE_TOP);
        startActivity(intent);
    }



}
