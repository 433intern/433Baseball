package com.example.sonjoy.test.client.Manager;

import android.transition.Scene;

import com.example.sonjoy.test.client.Scene.CLoginScene;
import com.example.sonjoy.test.client.Scene.CScene;

import java.util.LinkedList;

/**
 * Created by Sonjoy on 2015-12-07.
 */


public class CSceneManager {
    private static CSceneManager sceneManager = new CSceneManager();
    private LinkedList<CScene> mScenes;
    private boolean isRun;

    private CSceneManager() {
        isRun = false;
    }

    public static CSceneManager GetInstance()
    {
        return sceneManager;
    }

    public void Init()
    {
        mScenes = new LinkedList<CScene>();
        isRun = true;

    }

    public void ChangeScene(CScene scene)
    {
        if(!mScenes.isEmpty())
        {
            mScenes.removeLast();
        }

        mScenes.addLast(scene);
        mScenes.getLast().Init();
    }

    public void PushScene(CScene scene)
    {
        if(!mScenes.isEmpty())
        {

        }

        mScenes.addLast(scene);
        mScenes.getLast().Init();
    }

    public void PopScene(CScene scene)
    {
        if(!mScenes.isEmpty())
        {
            mScenes.removeLast();
        }

        if(!mScenes.isEmpty())
        {
            mScenes.getLast().Resume();
        }
    }

    public void Update()
    {
        if(!mScenes.isEmpty())
        {
            mScenes.getLast().Update();
        }

    }

    public boolean IsRunning() { return isRun;}
    public void Quit() { isRun = false; }
}
