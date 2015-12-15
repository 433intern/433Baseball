package com.example.sonjoy.baseballgameclient.SubActivity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import com.example.sonjoy.baseballgameclient.R;

/**
 * Created by Sonjoy on 2015-12-09.
 */
public class RoomActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_room);
        Toast.makeText(this, "onCreate() 호출", Toast.LENGTH_SHORT).show();
        this.setData();
    }

    @Override
    protected void onResume()
    {
        super.onResume();
        Toast.makeText(this, "onResume() 호출", Toast.LENGTH_SHORT).show();
    }

    public void roomStartBtnClicked(View v)
    {

        Intent intent = new Intent(RoomActivity.this, InGameActivity.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_SINGLE_TOP);
        startActivity(intent);

    }

    public void roomLeaveBtnClicked(View v)
    {

        Intent intent = new Intent(RoomActivity.this, LobbyActivity.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_SINGLE_TOP);
        startActivity(intent);

    }
    public void setData()
    {
        Intent intent = getIntent();
        String roomNum = intent.getExtras().get("ROOM_NUMBER").toString();

        TextView view = (TextView)findViewById(R.id.ROOM_ROOMNUM_VIEW);
        view.setText(roomNum + "번방");

    }
}