package com.example.sonjoy.baseballgameclient;


import android.app.Application;
import android.os.AsyncTask;

import com.example.sonjoy.baseballgameclient.Player.Player;
import com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
/**
 * Created by Sonjoy on 2015-12-13.
 */
public class BaseballApp extends Application {
//    private Player myPlayer, otherPlayer;
//
//
//    public class ClientSocket extends AsyncTask{
//        private String SERVER_IP = "127.0.0.1";
//        private int SERVER_PORT = 9000;
//
//        private Socket mSocket;
//
//        private OutputStream outStream;
//        private InputStream inputStream;
//
//        private final int HEADER_SIZE = 4;
//
//        private byte[] rcvHeaderBuf = new byte[HEADER_SIZE];
//        private byte[] rcvDataBuf;
//
//        ClientSocket(String addr, int port){
//           SERVER_IP = addr;
//           SERVER_PORT = port;
//
//           try {
//               InetAddress serverAddr = InetAddress.getByName(SERVER_IP);
//               mSocket = new Socket(serverAddr, SERVER_PORT);
//
//               outStream = mSocket.getOutputStream();
//               inputStream = mSocket.getInputStream();
//
//               rcvDataBuf = null;
//
//           } catch (UnknownHostException e) {
//               e.printStackTrace();
//           } catch (IOException e) {
//               e.printStackTrace();
//           }
//        }
//
//
//        @Override
//        protected Object doInBackground(Object... parmas){
//
//            int bytesRead = 0;
//
//            while(true)
//            {
//                try {
//                    bytesRead = inputStream.read(rcvHeaderBuf);
//
//                    if(bytesRead == 0) break;
//
//                    if(rcvHeaderBuf != null)
//                    {
//                        GamePacketEnumeration.PacketHeader header = GamePacketEnumeration.PacketHeader.parseFrom(rcvHeaderBuf);
//
//                        rcvDataBuf = new byte[header.getSize()];
//                        bytesRead = inputStream.read(rcvDataBuf);
//
//                        if(bytesRead == 0) break;
//
//                        recvProcess(rcvDataBuf, header.getType());
//
//                    }
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            }
//            return null;
//        }
//
//        public void recvProcess(byte[] rcvBuf, GamePacketEnumeration.PacketType type){
//
//            switch(type)
//            {
//                case SC_ROOM_CREATE_RESULT:
//
//                    break;
//                case SC_ROOM_JOIN_RESULT:
//
//                    break;
//                case SC_ROOM_LEAVE_RESULT:
//
//                    break;
//                case SC_INGAME_START_RESULT:
//
//                    break;
//                case SC_RECEIVE_BASEBALL_NUMBER_RESULT:
//
//                    break;
//                case SC_GIVE_TURN:
//
//                    break;
//                case SC_WAIT_TURN:
//
//                    break;
//                case SC_INGAME_END:
//
//                    break;
//                case UNKNOWN:
//
//                    break;
//
//            }
//
//
//
//
//        }
//
//
//
//    }
//
//
//    @Override
//    public void onCreate(){
//        super.onCreate();
//    }
//
//    @Override
//    public void onTerminate(){
//        super.onTerminate();
//    }


}

