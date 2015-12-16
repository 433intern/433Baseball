package com.example.sonjoy.baseballgameclient;


import android.app.Application;
import android.content.Intent;
import android.net.wifi.WifiConfiguration;
import android.os.AsyncTask;
import android.util.Log;
import android.widget.Toast;

import com.example.sonjoy.baseballgameclient.Common.PlayerStatus;
import com.example.sonjoy.baseballgameclient.Player.Player;
import com.example.sonjoy.baseballgameclient.SubActivity.AccountCreateActivity;
import com.example.sonjoy.baseballgameclient.SubActivity.LobbyActivity;
import com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration;
import com.example.sonjoy.baseballgameclient.protocol.LoginMessage;
import com.example.sonjoy.baseballgameclient.protocol.RoomPacket;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Inet4Address;
import java.net.Inet6Address;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.Socket;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.Enumeration;

/**
 * Created by Sonjoy on 2015-12-13.
 */
public class BaseballApp extends Application
{
    private static BaseballApp appInstance;

    @Override
    public void onCreate()
    {
        super.onCreate();
        GAME_SERVER_IP = null;
        GAME_SERVER_PORT = -1;
        securityCode = null;

        appInstance = this;

        Log.d("Global" , "onCreate()");
    }

    @Override
    public void onTerminate()
    {
        super.onTerminate();

        Log.d("Global", "onTerminated()");
    }

    public static BaseballApp Instance()
    {
        return appInstance;
    }

    // Game Server
    private Player myPlayer, otherPlayer;
    private ClientSocket mClientSocket;
    private String GAME_SERVER_IP;
    private int GAME_SERVER_PORT;
    private String securityCode;


    // Login Server
    private Socket mRefLoginSocket = null;
    private boolean isAccountCreateSuccess = false;
    private boolean isRepeatCreate = false;

    public class ClientSocket extends AsyncTask{


        private Socket mSocket;

        private OutputStream outStream;
        private InputStream inputStream;

        private final int HEADER_SIZE = 10;

        private byte[] rcvHeaderBuf = new byte[HEADER_SIZE];
        private byte[] rcvDataBuf;

        private boolean isConnected = false;

        ClientSocket(String addr, int port)
        {
            GAME_SERVER_IP = addr;
            GAME_SERVER_PORT = port;
        }

        @Override
        protected void onPreExecute()
        {
            super.onPreExecute();

        }

        @Override
        protected Object doInBackground(Object... parmas)
        {

            try {
                InetAddress serverAddr = InetAddress.getByName(GAME_SERVER_IP);
                mSocket = new Socket(serverAddr, GAME_SERVER_PORT);

                if(mSocket != null) isConnected = true;

                outStream = mSocket.getOutputStream();
                inputStream = mSocket.getInputStream();

                rcvDataBuf = null;

            } catch (UnknownHostException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }

            sendRoomInfoRequest();

            int bytesRead = 0;

            while(isConnected)
            {
                try {
                    bytesRead = inputStream.read(rcvHeaderBuf);

                    if(bytesRead == 0) break;

                    if(rcvHeaderBuf != null)
                    {
                        GamePacketEnumeration.PacketHeader header = GamePacketEnumeration.PacketHeader.parseFrom(rcvHeaderBuf);

                        rcvDataBuf = new byte[header.getSize()];
                        bytesRead = inputStream.read(rcvDataBuf);

                        if(bytesRead == 0) break;

                        recvProcess(rcvDataBuf, header.getType());
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }

                try {
                    mSocket.close();

                } catch (IOException e) {
                    e.printStackTrace();
                }

            }
            return null;
        }



        public void recvProcess(byte[] rcvBuf, int type)
        {

            switch(type)
            {
                case GamePacketEnumeration.PacketType.SC_ROOM_CREATE_RESULT_VALUE:

                    break;
                case GamePacketEnumeration.PacketType.SC_ROOM_JOIN_RESULT_VALUE:

                    break;
                case GamePacketEnumeration.PacketType.SC_ROOM_LEAVE_RESULT_VALUE:

                    break;
                case GamePacketEnumeration.PacketType.SC_INGAME_START_RESULT_VALUE:

                    break;
                case GamePacketEnumeration.PacketType.SC_RECEIVE_BASEBALL_NUMBER_RESULT_VALUE:

                    break;
                case GamePacketEnumeration.PacketType.SC_GIVE_TURN_VALUE:

                    break;
                case GamePacketEnumeration.PacketType.SC_WAIT_TURN_VALUE:

                    break;
                case GamePacketEnumeration.PacketType.SC_INGAME_END_VALUE:

                    break;
                case GamePacketEnumeration.PacketType.UNKNOWN_VALUE:

                    break;

            }
        }
        @Override
        protected void onPostExecute(Object result)
        {
            super.onPostExecute(result);
        }

        public OutputStream getOutputStream()
        {
            if(outStream == null) return null;
            return outStream;
        }



        public boolean IsConnected() { return this.isConnected;}

        public void sendRoomInfoRequest()
        {
            if(isConnected)
            {
                RoomPacket.CS_room_info_request payload = RoomPacket.CS_room_info_request.newBuilder()
                        .build();

                GamePacketEnumeration.PacketHeader header = GamePacketEnumeration.PacketHeader.newBuilder()
                        .setSize(payload.getSerializedSize())
                        .setType(GamePacketEnumeration.PacketType.CS_ROOM_INFO_REQUEST_VALUE)
                        .build();

                BaseballApp.Instance().sendUnionPacket(outStream, header.toByteArray(), payload.toByteArray());
            }
        }


    }

    public void GameServerConnection(String ip, int port)
    {
        mClientSocket = new ClientSocket(ip,port);

        mClientSocket.executeOnExecutor(AsyncTask.THREAD_POOL_EXECUTOR,"");

    }

    public void initMyPlayer(String nickName, String password, String securityCode, PlayerStatus status)
    {
        myPlayer = new Player(nickName, password, securityCode, status);
    }

    public Player getMyPlayer() { return myPlayer; }

    public void sendUnionPacket(OutputStream outStream, byte[] header, byte[] payload)
    {
        try {
            outStream.write(header);
            outStream.write(payload);
            outStream.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void sendUnionPacket(byte[] header, byte[] payload)
    {
        if(mClientSocket == null) return;

        sendUnionPacket(mClientSocket.getOutputStream(), header, payload);
    }

    public void setGameServerIP(String ip){ GAME_SERVER_IP = ip;}
    public void setGameServerPort(int port) { GAME_SERVER_PORT = port;}
    public void setSecurityCode(String code) { securityCode = code;}
    public void setAccountCreateSuccess(boolean isSuccess) { isAccountCreateSuccess = isSuccess;}
    public void setIsAccountRepeatCreate(boolean isRepeat) { isRepeatCreate = isRepeat; }

    public String getGameServerIP() { return GAME_SERVER_IP;}
    public int getGameServerPort() { return GAME_SERVER_PORT; }
    public String getSercurityCode() { return securityCode; }

    public boolean IsAccountCreateSuccess() { return isAccountCreateSuccess;}
    public boolean IsAccountRepeatCreate() { return isRepeatCreate; }

    public boolean IsGameServerConnected()
    {
       if(mClientSocket != null) {
           return mClientSocket.IsConnected();
       }
       return false;
    }

    public void setRefLoginSocket(Socket socket) { mRefLoginSocket = socket; }
    public Socket getRefLoginSocket() { return mRefLoginSocket; }


}

