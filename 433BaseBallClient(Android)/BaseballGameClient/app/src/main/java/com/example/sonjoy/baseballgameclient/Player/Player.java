package com.example.sonjoy.baseballgameclient.Player;


import com.example.sonjoy.baseballgameclient.Common.PlayerStatus;

/**
 * Created by Sonjoy on 2015-12-11.
 */

public class Player {
    private String mID;
    private String mPassword;
    private String mSecurityCode;
    private int myRoomNumber = -1;
    private PlayerStatus mStatus;


    public Player(String id, String password, String securityCode, PlayerStatus status){
        mID = new String(id);
        mPassword = new String(password);
        mStatus = new PlayerStatus();

        if(status != null)
        {
            mStatus.winCount = status.winCount;
            mStatus.loseCount = status.loseCount;

        }

        mSecurityCode = new String(securityCode);
    }

    public void Init(String id, String password){

        mID = new String(id);
        mPassword = new String(password);
        mStatus = new PlayerStatus();
    }

    public void setID(String id){
        this.mID = id;
    }

    public String getID(){
        return this.mID;
    }

    public void setPassWord(String password){
        this.mPassword = password;
    }

    public String getPassword(){
        return this.mPassword;
    }

    public void setRoomNumber(int roomNum){
        this.myRoomNumber = roomNum;
    }

    public Integer getRoomNumber(){
        return this.myRoomNumber;
    }

    public void setStatus(int winCnt, int loseCnt, int strikeCnt, int ballCnt, int outCnt){
        this.mStatus.winCount = winCnt;
        this.mStatus.loseCount = loseCnt;
    }

    public PlayerStatus getStatus(){
        return this.mStatus;
    }

    public void setSecurityCode(String securityCode) { this.mSecurityCode = securityCode;}
    public String getSecurityCode() { return mSecurityCode; }





}
