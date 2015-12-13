package com.example.sonjoy.baseballgameclient.SubActivity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.example.sonjoy.baseballgameclient.R;

/**
 * Created by Sonjoy on 2015-12-09.
 */
public class InGameActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ingame);
        Toast.makeText(this, "onCreate() 호출", Toast.LENGTH_SHORT).show();
    }

    @Override
    protected void onResume(){
        super.onResume();
        Toast.makeText(this, "onResume() 호출", Toast.LENGTH_SHORT).show();
    }

    public void ingameLeaveClicked(View v){
        Intent intent = new Intent(InGameActivity.this, RoomActivity.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_SINGLE_TOP);
        startActivity(intent);


    }


}
