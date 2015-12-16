package com.example.sonjoy.baseballgameclient.SubActivity;

import android.app.Activity;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.HorizontalScrollView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import com.example.sonjoy.baseballgameclient.BaseballApp;
import com.example.sonjoy.baseballgameclient.Common.PlayerStatus;
import com.example.sonjoy.baseballgameclient.Common.RoomInfo;
import com.example.sonjoy.baseballgameclient.MainActivity;
import com.example.sonjoy.baseballgameclient.Player.Player;
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
    private LobbyRefreshTask lobbyUITask;

    private LinkedList<Button> btnList;
    private View.OnClickListener listner;
    private String playerViewID = null;
    private PlayerStatus playerViewStatus = null;
    private String editRoomNum = null;

    private boolean isCreate = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lobby);

        Toast.makeText(this, "onCreate() 호출", Toast.LENGTH_SHORT).show();

        btnList = new LinkedList<Button>();

        playerViewID = BaseballApp.Instance().getMyPlayer().getID();
        playerViewStatus = BaseballApp.Instance().getMyPlayer().getStatus();
        setMyInfoView();

        new Thread(new Runnable() {
            @Override
            public void run() {
                {
                    /// Contact Packet Send
                    RoomPacket.CS_contact_alram contactPayload = RoomPacket.CS_contact_alram.newBuilder()
                            .setNickName(playerViewID)
                            .setSecurityCode(BaseballApp.Instance().getMyPlayer().getSecurityCode())
                            .build();

                    GamePacketEnumeration.PacketHeader contactHeader = GamePacketEnumeration.PacketHeader.newBuilder()
                            .setSize(contactPayload.getSerializedSize())
                            .setType(GamePacketEnumeration.PacketType.CS_CONTACT_ALRAM_VALUE)
                            .build();

                    BaseballApp.Instance().sendUnionPacket(contactHeader.toByteArray(), contactPayload.toByteArray());

                    /// Lobby Total Room Info Request Send
                    RoomPacket.CS_total_room_info_request totalRoomPayload = RoomPacket.CS_total_room_info_request.newBuilder()
                            .build();

                    GamePacketEnumeration.PacketHeader totalRoomHeader = GamePacketEnumeration.PacketHeader.newBuilder()
                            .setSize(totalRoomPayload.getSerializedSize())
                            .setType(GamePacketEnumeration.PacketType.CS_TOTAL_ROOM_INFO_REQUEST_VALUE)
                            .build();

                    BaseballApp.Instance().sendHeaderPacket(totalRoomHeader.toByteArray());
                }

            }
        }).start();


        listner = new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                final int roomNum = v.getId();

                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        {
                            RoomPacket.CS_room_join payload = RoomPacket.CS_room_join.newBuilder()
                                    .setRoomNum(roomNum)
                                    .build();

                            GamePacketEnumeration.PacketHeader header = GamePacketEnumeration.PacketHeader.newBuilder()
                                    .setSize(payload.getSerializedSize())
                                    .setType(GamePacketEnumeration.PacketType.CS_ROOM_JOIN_VALUE)
                                    .build();

                            BaseballApp.Instance().sendUnionPacket(header.toByteArray(), payload.toByteArray());
                        }
                    }
                }).start();


            }
        };

        lobbyUITask = new LobbyRefreshTask();
        lobbyUITask.executeOnExecutor(AsyncTask.THREAD_POOL_EXECUTOR,"");

    }

    @Override
    protected void onResume(){
        super.onResume();
        Toast.makeText(this, "onResume() 호출", Toast.LENGTH_SHORT).show();


        if (isCreate) {
            BaseballApp.Instance().setClientState(BaseballApp.CLIENT_STATE.LOBBY);
            lobbyUITask = new LobbyRefreshTask();
            lobbyUITask.executeOnExecutor(AsyncTask.THREAD_POOL_EXECUTOR,"");

            new Thread(new Runnable() {
                @Override
                public void run() {
                    {
                        /// Lobby Total Room Info Request Send
                        RoomPacket.CS_total_room_info_request totalRoomPayload = RoomPacket.CS_total_room_info_request.newBuilder()
                                .build();

                        GamePacketEnumeration.PacketHeader totalRoomHeader = GamePacketEnumeration.PacketHeader.newBuilder()
                                .setSize(totalRoomPayload.getSerializedSize())
                                .setType(GamePacketEnumeration.PacketType.CS_TOTAL_ROOM_INFO_REQUEST_VALUE)
                                .build();

                        BaseballApp.Instance().sendUnionPacket(totalRoomHeader.toByteArray(), totalRoomPayload.toByteArray());
                    }

                }
            }).start();
        }

        isCreate = true;
    }

    public void roomCreateBtnClicked(View v){

        final EditText roomNumEdit = (EditText)findViewById(R.id.LOBBY_ROOMNUM_EDIT);
        editRoomNum = roomNumEdit.getText().toString();

        new Thread(new Runnable() {
            @Override
            public void run() {
                {
                    /// Lobby Room Create
                    RoomPacket.CS_room_create payload = RoomPacket.CS_room_create.newBuilder()
                            .setRoomNum(Integer.parseInt(roomNumEdit.getText().toString()))
                            .build();

                    GamePacketEnumeration.PacketHeader header = GamePacketEnumeration.PacketHeader.newBuilder()
                            .setSize(payload.getSerializedSize())
                            .setType(GamePacketEnumeration.PacketType.CS_ROOM_CREATE_VALUE)
                            .build();

                    BaseballApp.Instance().sendUnionPacket(header.toByteArray(), payload.toByteArray());
                }
            }
        }).start();


    }
    public void setMyInfoView()
    {
        TextView myInfoIDView = (TextView)findViewById(R.id.LOBBY_MY_INFO_ID);
        TextView myInfoWinView = (TextView)findViewById(R.id.LOBBY_MY_INFO_WIN);
        TextView myInfoLoseView = (TextView)findViewById(R.id.LOBBY_MY_INFO_LOSE);

        myInfoIDView.setText(playerViewID);
        myInfoWinView.setText(Integer.toString(playerViewStatus.winCount));
        myInfoLoseView.setText(Integer.toString(playerViewStatus.loseCount));

    }

    public class LobbyRefreshTask extends AsyncTask
    {
        @Override
        protected Object doInBackground(Object... parmas)
        {
            while(BaseballApp.Instance().getMyState() == BaseballApp.CLIENT_STATE.LOBBY)
            {
                if(BaseballApp.Instance().IsLobbyRefresh())
                {
                    publishProgress(null);
                    BaseballApp.Instance().setIsLobbyRefresh(false);
                }
            }
            return null;
        }

        @Override
        protected void onProgressUpdate(Object... progress)
        {
            LinearLayout layout = (LinearLayout) findViewById(R.id.LOBBY_SCROLL_LAYOUT);

            if(!BaseballApp.Instance().getRooms().isEmpty())
            {
                layout.removeAllViews();

                for (RoomInfo room : BaseballApp.Instance().getRooms())
                {
                    Button btn = new Button(LobbyActivity.this);
                    btn.setText(Integer.toString(room.roomNum));
                    btn.setWidth(50);
                    btn.setTextSize(20);
                    btn.setId(room.roomNum);
                    btn.setOnClickListener(listner);
                    btnList.add(btn);

                    layout.addView(btn);
                }
            }
        }

        @Override
        protected void onPostExecute(Object result)
        {
            super.onPostExecute(result);

            int joinRoomNumber = BaseballApp.Instance().getMyPlayer().getRoomNumber();
            Toast.makeText(LobbyActivity.this, Integer.toString(joinRoomNumber) + "번방으로 입장합니다.", Toast.LENGTH_SHORT).show();

            Intent intent = new Intent(LobbyActivity.this, RoomActivity.class);
            intent.putExtra("ROOM_NUMBER", joinRoomNumber);
            intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_SINGLE_TOP);

            startActivity(intent);
        }
    }



}
