package com.tiquillo.tutoria;

import static com.tiquillo.tutoria.MainActivity.SERVER_IP;

import androidx.appcompat.app.AppCompatActivity;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class MainActivity2 extends AppCompatActivity implements SensorEventListener {
    TextView puntaje;
    TextView vidas;
    TextView nivel;
    static String puntajed = "PUNTAJE";
    static String vidasd = "VIDAS";
    static String niveld = "NIVEL";
    SensorManager sensorManager;
    Sensor accelerometerSensor;
    float x,y,z;
    private Socket socket;
    private BufferedReader input;
    private PrintWriter output;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        puntaje = findViewById(R.id.txtpuntaje);
        vidas = findViewById(R.id.txtvidas);
        nivel = findViewById(R.id.txtnivel);

        sensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);
        accelerometerSensor = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);

    }
    @Override
    protected void onResume() {
        super.onResume();
        sensorManager.registerListener(this, accelerometerSensor, SensorManager.SENSOR_DELAY_NORMAL);
    }

    @Override
    protected void onPause() {
        super.onPause();
        sensorManager.unregisterListener(this);
    }
    @Override
    public void onSensorChanged(SensorEvent sensorEvent) {
        if (sensorEvent.sensor.getType() == Sensor.TYPE_ACCELEROMETER) {
            x = sensorEvent.values[0];
            y = sensorEvent.values[1];
            z = sensorEvent.values[2];
            EnviarInfo();
            //puntaje.setText("AAAAAAAAA");
            //vidas.setText(vidasd);
            //nivel.setText(niveld);
            //System.out.println("Gyro: x=" + x + ", y=" + y + ", z=" + z);

        }
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int i) {

    }
    private void EnviarInfo() {
        new Thread(() -> {
            String a = "";
            try {
                socket = new Socket(SERVER_IP, 5001);
                input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                output = new PrintWriter(socket.getOutputStream(), true);

                String message = x + "," + y + "," + z;
                output.printf(message);
                Log.d("ENVIADO", message);


                String response = input.readLine();
                if (response != null){
                    String[] values = response.split(",");
                    if (values.length >= 3) {
                        puntajed = values[0];
                        vidasd = values[1];
                        niveld = values[2];
                        System.out.println("Accelerometer: x=" + puntajed + ", y=" + vidasd + ", z=" + niveld);
                        Log.d("RESPUESTA", response);
                        runOnUiThread(() -> {
                            puntaje.setText("PUNTAJE:" + puntajed);
                            vidas.setText("VIDAS:" + vidasd);
                            nivel.setText("NIVEL:" + niveld);
                        });
                    }
                }


                socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }).start();
    }

}