package com.example.sonjoy.baseballgameclient.Player;

import com.example.sonjoy.baseballgameclient.Common.PlayerStatus;

/**
 * Created by Sonjoy on 2015-12-13.
 */
public class OtherPlayer {
    private String mID = null;
    private int myRoomNumber = -1;

    public OtherPlayer(String id, int roomNumber)
    {
        mID = new String(id);
        myRoomNumber = roomNumber;
    }
    public String getID() { return mID; }
    public int getRoomNumber() { return myRoomNumber; }
}
