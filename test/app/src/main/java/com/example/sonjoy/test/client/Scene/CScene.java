package com.example.sonjoy.test.client.Scene;

/**
 * Created by Sonjoy on 2015-12-07.
 */
abstract public class CScene {
    public abstract void Init();
    public abstract void Free();

    public abstract void Pause();
    public abstract void Resume();

    public abstract void Update();

}
