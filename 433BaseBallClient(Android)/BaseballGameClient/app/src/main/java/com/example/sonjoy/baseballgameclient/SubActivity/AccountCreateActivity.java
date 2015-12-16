package com.example.sonjoy.baseballgameclient.SubActivity;

import android.app.Activity;
import android.content.Intent;
import android.os.AsyncTask;
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

    private AcitivitySwitchTask switchTask = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_account_create);

        //Toast.makeText(this, "onCreate() 호출", Toast.LENGTH_SHORT).show();

        switchTask = new AcitivitySwitchTask();
        switchTask.executeOnExecutor(AsyncTask.THREAD_POOL_EXECUTOR, "");

    }

    public void accountCreateBtnClicked(View v)
    {
        EditText idEdit = (EditText)findViewById(R.id.ACCOUNT_ID_EDIT);
        EditText passwordEdit = (EditText)findViewById(R.id.ACCOUNT_PASSWORD_EDIT);

        final String id = idEdit.getText().toString();
        final String password = passwordEdit.getText().toString();


        new Thread(new Runnable() {
            @Override
            public void run()
            {
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
    }
    public class AcitivitySwitchTask extends AsyncTask
    {
        @Override
        protected Object doInBackground(Object... parmas)
        {
            while(!BaseballApp.Instance().IsAccountCreateSuccess())
            {
                if(BaseballApp.Instance().IsAccountRepeatCreate())
                {
                    publishProgress(null);
                    BaseballApp.Instance().setIsAccountRepeatCreate(false);
                }
            }

            return null;
        }

        @Override
        protected void onProgressUpdate(Object... progress)
        {
            Toast.makeText(AccountCreateActivity.this, "계정 생성 실패", Toast.LENGTH_SHORT).show();
        }

        @Override
        protected void onPostExecute(Object result)
        {
            super.onPostExecute(result);
            Toast.makeText(AccountCreateActivity.this, "계정 생성 성공", Toast.LENGTH_SHORT).show();

            BaseballApp.Instance().setAccountCreateSuccess(false);
            BaseballApp.Instance().setIsAccountRepeatCreate(false);

            Intent intent = new Intent(AccountCreateActivity.this, MainActivity.class);
            intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_SINGLE_TOP);
            startActivity(intent);
        }
    }
}
