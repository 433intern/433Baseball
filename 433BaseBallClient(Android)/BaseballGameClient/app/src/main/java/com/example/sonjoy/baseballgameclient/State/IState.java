package com.example.sonjoy.baseballgameclient.State;

import android.view.MotionEvent;

/**
 * Created by Sonjoy on 2015-12-09.
 */
public interface IState{
    public void Init();
    public void Destroy();
    public void Update();

    public boolean onTouchEvent(MotionEvent event);
}
