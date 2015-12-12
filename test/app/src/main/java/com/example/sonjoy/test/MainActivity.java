package com.example.sonjoy.test;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import com.example.sonjoy.test.client.AddressBookProtos.Person;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;

public class MainActivity extends AppCompatActivity {
    private Socket mSocket;
    private static final int SERVER_PORT = 9000;
    private static final String SERVER_IP = "10.100.58.3";


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        new Thread(new ClientThread()).start();
    }



    class ClientThread implements Runnable{

        @Override
        public void run(){

            try {
                InetAddress serverAddr = InetAddress.getByName(SERVER_IP);
                mSocket = new Socket(serverAddr, SERVER_PORT);

                OutputStream out = mSocket.getOutputStream();
                DataOutputStream dos = new DataOutputStream(out);

                Person srcPerson = Person.newBuilder()
                        .setId(12345)
                        .setName("son")
                        .setEmail("sonsational@naver.com")
                        .addPhone(Person.PhoneNumber.newBuilder()
                                .setNumber("+351 999 999 999")
                                .setType(Person.PhoneType.HOME)
                                .build())
                        .build();

                dos.write(srcPerson.toByteArray());

                InputStream in = mSocket.getInputStream();
                DataInputStream dis = new DataInputStream(in);

                byte[] recvBuf = new byte[53];
                dis.read(recvBuf);
                Person dstPerson = Person.parseFrom(recvBuf);

                System.out.print(dstPerson.getEmail());
                System.out.print(dstPerson.getId());
                System.out.print(dstPerson.getName());
                Log.i("tag",dstPerson.getEmail());

//                srcPerson.writeDelimitedTo(mSocket.getOutputStream());

            } catch (IOException e) {
                e.printStackTrace();
            }

        }


    }

}

