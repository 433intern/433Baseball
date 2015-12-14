package com.example.sonjoy.baseballgameclient.SubActivity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.HorizontalScrollView;
import android.widget.LinearLayout;
import android.widget.Toast;

import com.example.sonjoy.baseballgameclient.BaseballApp;
import com.example.sonjoy.baseballgameclient.R;
import com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration;
import com.example.sonjoy.baseballgameclient.protocol.LoginMessage;
import com.example.sonjoy.baseballgameclient.protocol.RoomPacket;

import java.io.IOException;
import java.util.LinkedList;

/**
 * Created by Sonjoy on 2015-12-09.
 */
public class LobbyActivity extends Activity {
    LinkedList<Button> btnList;
    View.OnClickListener listner;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lobby);
        Toast.makeText(this, "onCreate() 호출", Toast.LENGTH_SHORT).show();
        btnList = new LinkedList<Button>();


        new Thread(new Runnable() {
            @Override
            public void run() {
                {
                    RoomPacket.CS_room_info_request payload = RoomPacket.CS_room_info_request.newBuilder().build();

                    GamePacketEnumeration.PacketHeader header = GamePacketEnumeration.PacketHeader.newBuilder()
                            .setSize(payload.getSerializedSize())
                            .setType(GamePacketEnumeration.PacketType.CS_ROOM_INFO_REQUEST_VALUE)
                            .build();

                    BaseballApp.Instance().sendUnionPacket(header.toByteArray(), payload.toByteArray());
                }

            }
        }).start();



        listner = new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                Toast.makeText(LobbyActivity.this, Integer.toString(v.getId()) + "번방으로 입장합니다.", Toast.LENGTH_SHORT).show();

                Intent intent = new Intent(LobbyActivity.this, RoomActivity.class);
                intent.putExtra("ROOM_NUMBER", v.getId());
                intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_SINGLE_TOP);

                startActivity(intent);
            }
        };





    }
    @Override
    protected void onResume(){
        super.onResume();
        Toast.makeText(this, "onResume() 호출", Toast.LENGTH_SHORT).show();
    }

    public void roomCreateBtnClicked(View v){

        LinearLayout layout = (LinearLayout) findViewById(R.id.LOBBY_SCROLL_LAYOUT);

        EditText roomNumEdit = (EditText)findViewById(R.id.LOBBY_ROOMNUM_EDIT);

        //Intent intent = new Intent(this, RoomActivity.class);
        //intent.putExtra("ROOM_NUMBER", roomNumEdit.getText());

        Button btn = new Button(this);
        btn.setText(roomNumEdit.getText());
        btn.setWidth(50);
        btn.setTextSize(20);
        btn.setId(Integer.parseInt(roomNumEdit.getText().toString()));
        btn.setOnClickListener(listner);
        btnList.add(btn);


        layout.addView(btn);



       // startActivity(intent);
    }

    public void setData() {
        Intent intent = getIntent();
        String id = intent.getExtras().get("ID").toString();
        String password = intent.getExtras().get("PASSWORD").toString();

    }



}
