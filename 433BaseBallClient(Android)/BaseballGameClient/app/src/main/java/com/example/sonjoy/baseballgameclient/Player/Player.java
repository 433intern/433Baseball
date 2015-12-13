package com.example.sonjoy.baseballgameclient.Player;

/**
 * Created by Sonjoy on 2015-12-11.
 */
public class Player {
    class Status{
        int winCount = 0;
        int loseCount = 0;
        int strikeCount = 0;
        int ballCount = 0;
        int outCount = 0;
    }

    private String mID;
    private String mPassword;
    private int myRoomNumber = -1;
    private Status mStatus;


    Player(){
        mID = null;
        mPassword = null;
        mStatus = null;
    }

    public void Init(String id, String password){

        mID = new String(id);
        mPassword = new String(password);
        mStatus = new Status();
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
        this.mStatus.strikeCount = strikeCnt;
        this.mStatus.ballCount = ballCnt;
        this.mStatus.outCount = outCnt;
    }

    public Status getStatus(){
        return this.mStatus;
    }






}
