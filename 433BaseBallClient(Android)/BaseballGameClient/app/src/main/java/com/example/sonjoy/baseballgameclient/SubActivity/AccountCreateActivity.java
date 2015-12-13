package com.example.sonjoy.baseballgameclient.SubActivity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.example.sonjoy.baseballgameclient.MainActivity;
import com.example.sonjoy.baseballgameclient.R;

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

    public void accountCreateBtnClicked(View v){

        Intent intent = new Intent(AccountCreateActivity.this, MainActivity.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_SINGLE_TOP);
        startActivity(intent);
    }



}
