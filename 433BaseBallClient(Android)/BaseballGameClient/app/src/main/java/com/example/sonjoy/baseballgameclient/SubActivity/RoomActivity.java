package com.example.sonjoy.baseballgameclient.SubActivity;

import android.app.Activity;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import com.example.sonjoy.baseballgameclient.BaseballApp;
import com.example.sonjoy.baseballgameclient.Common.RoomInfo;
import com.example.sonjoy.baseballgameclient.Player.OtherPlayer;
import com.example.sonjoy.baseballgameclient.R;
import com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration;
import com.example.sonjoy.baseballgameclient.protocol.RoomPacket;

import java.util.ArrayList;

/**
 * Created by Sonjoy on 2015-12-09.
 */
public class RoomActivity extends Activity {
    private RoomRefreshTask roomUITask = null;

    private OtherPlayer otherPlayer = null;

    private int currRoomNumber = -1;

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

        roomUITask = new RoomRefreshTask();
        roomUITask.executeOnExecutor(AsyncTask.THREAD_POOL_EXECUTOR, "");

        new Thread(new Runnable() {
            @Override
            public void run() {
                {
                    /// Lobby Total Room Info Request Send
                    RoomPacket.CS_room_info_request payload = RoomPacket.CS_room_info_request.newBuilder()
                            .setRoomNum(currRoomNumber)
                            .build();

                    GamePacketEnumeration.PacketHeader header = GamePacketEnumeration.PacketHeader.newBuilder()
                            .setSize(payload.getSerializedSize())
                            .setType(GamePacketEnumeration.PacketType.CS_ROOM_INFO_REQUEST_VALUE)
                            .build();

                    BaseballApp.Instance().sendUnionPacket(header.toByteArray(), payload.toByteArray());
                }

            }
        }).start();


    }

    public void roomStartBtnClicked(View v)
    {

        Intent intent = new Intent(RoomActivity.this, InGameActivity.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_SINGLE_TOP);
        startActivity(intent);

    }

    public void roomLeaveBtnClicked(View v)
    {

        new Thread(new Runnable() {
            @Override
            public void run() {
                {
                    RoomPacket.CS_room_leave payload = RoomPacket.CS_room_leave.newBuilder()
                            .setRoomNum(currRoomNumber)
                            .build();

                    GamePacketEnumeration.PacketHeader header = GamePacketEnumeration.PacketHeader.newBuilder()
                            .setSize(payload.getSerializedSize())
                            .setType(GamePacketEnumeration.PacketType.CS_ROOM_LEAVE_VALUE)
                            .build();

                    BaseballApp.Instance().sendUnionPacket(header.toByteArray(), payload.toByteArray());
                }

            }
        }).start();



    }
    public void setData()
    {
        Intent intent = getIntent();

        String roomNum = intent.getExtras().get("ROOM_NUMBER").toString();
        currRoomNumber = Integer.parseInt(roomNum);

        TextView view = (TextView)findViewById(R.id.ROOM_ROOMNUM_VIEW);
        view.setText(roomNum + "번방");

    }
    public class RoomRefreshTask extends AsyncTask
    {
        @Override
        protected Object doInBackground(Object... parmas)
        {
            while(BaseballApp.Instance().getMyState() == BaseballApp.CLIENT_STATE.ROOM)
            {
                if(BaseballApp.Instance().IsRoomRefresh())
                {
                    publishProgress(null);
                    BaseballApp.Instance().setIsRoomRefresh(false);
                }
            }
            return null;
        }

        @Override
        protected void onProgressUpdate(Object... progress)
        {
            TextView[] idViews = new TextView[2];
            idViews[0] = (TextView)findViewById(R.id.ROOM_ID_VIEW_1);
            idViews[1] = (TextView)findViewById(R.id.ROOM_ID_VIEW_2);

            int index = 0;
            for(String id : BaseballApp.Instance().getPlayerIDs())
            {
                idViews[index].setText(id);
                index++;
            }

        }

        @Override
        protected void onPostExecute(Object result)
        {
            super.onPostExecute(result);

            Intent intent = new Intent(RoomActivity.this, LobbyActivity.class);
            intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_SINGLE_TOP);
            startActivity(intent);
        }
    }



}