#include <Arduino.h>
// #include <WiFi.h>
#include "device_config.h"

//Preferences last value
//Batt 36

bool read_state = false;
unsigned long last_read = 0;

void setup() {
  Serial.begin(115200);
  // WiFi.begin("R3", "01062003");
  lcd.init();
  motor.begin();
  battery.begin();
  bpm.begin();
  // bpm.stop();
  pressure.begin();
  temp.begin();
  pinMode(14, INPUT);
  delay(2000);
  lcd.boot();
}

void loop() {
  if(digitalRead(14)){
    float dumpTEMP = 0.0, temp_now;
    int dumpBPM = 0, dumpSPO = 0, bpm_now, n = 0, spo_now;

    read_state = true;
    String val = String(temp.temperature()) + " c";
    data.save("temp", val);
    Serial.println(val);
    lcd.show(val);
    delay(500);

    bpm.start();
    String val2 = String(bpm.bpm()) + " bpm";
    data.save("bpm", val2);
    Serial.println(val2);
    lcd.show(val2);
    bpm.stop();
    delay(500);
    
    // 5s bpm + spo2
    bpm.start();
    for(int i = 0; i >= 5000; i++){
      bpm.update();
      int bpmSens = bpm.bpm() + 15;
      int spoSens = bpm.spo2();
      float tempSens = temp.temperature() + 2.5;

      if (bpmSens >= 40.0 && bpmSens <= 200.0 && spoSens >= 80 && spoSens <= 100 && tempSens >= 34.0 && tempSens <= 45.0) { //batas rata2 pengukuran
        dumpBPM += bpmSens;
        dumpSPO += spoSens;
        dumpTEMP += tempSens;
        n++;

        bpm_now = dumpBPM / n;       //kalibrasi bpm
        spo_now = dumpSPO / n;        //kalibrasi spo
        temp_now = dumpTEMP / n;     //kalibrasi suhu
      }
    }
    bpm.stop();

    String s1 = "BPM  : " + String(bpm_now) + "";
    String s2 = "SPO2 : " + String(spo_now) + " %";
    String s3 = "SUHU : " + String(temp_now) + " *C";
    
    lcd.show(s1);
    delay(1000);
    lcd.show(s2);
    delay(1000);
    lcd.show(s3);
    delay(1000);
    
    // show loading finger
    // show real time val
    
    // save data

    // 5s temp
    // show loading finger
    // show real time val

    // save data

    // sistol + diastol
    // show loading muscle
    // show real time val
    int adc0 = 0, sis = 0, dis = 0, mmhg = 0, lastmmhg = 0, mark = 0, adc1 = 0;
        
    motor.start();
    mmhg = pressure.mmhg();

    while(mmhg < 150){
      mmhg = pressure.mmhg();
      
      Serial.print("Sistol : ");
      Serial.print(mmhg);
      Serial.println(" mmhg");
      lastmmhg = mmhg;

      String s1 = ": " + String(mmhg) + " mmhg      ";
      
      lcd.show(s1);
      delay(50);
    }

    motor.pause();
    
    while(mmhg > 70){
      mmhg = pressure.mmhg();

      String s2 = ": " + String(mmhg) + " mmhg      ";
      Serial.print("Diastol : ");
      Serial.print(mmhg);
      Serial.println(" mmhg");

      lcd.show(s2);    

      if(lastmmhg <= mmhg){ //deteksi detak jantung
        if(mark==0){
          mark=1;
        } else if(mark==1){
          sis=mmhg;
          mark++;
        } else if(mark>1){
          mark++;
          dis=mmhg;
        }
        delay(100);
      }

      if(mark>10) break;
      
      lastmmhg = mmhg;
      delay(100);
    }

    motor.stop();
    delay(1000);

    sis *= 0.95;  //kalibrasi sistol, nilai sistol = sistol x 0,95
    dis *= 0.85;  //kalibrasi diastol, nilai diastol = diastol x 0,85
    
    s1 = "BPM  : " + String(bpm_now) + "";
    s2 = "SPO2 : " + String(spo_now) + " %";
    s3 = "SUHU : " + String(temp_now) + " *C";
    String s4 = "SIS  : " + String(sis) + " mmhg";
    String s5 = "DIS  : " + String(dis) + " mmhg";



    // save data
  }

  if(read_state && millis() - last_read > 5000){
    // read saved data
    // show saved data
    // update battery
    last_read = millis();
  }
}
