#include <Arduino.h>
#include "device_config.h"

bool read_state = false;
unsigned long last_read = 0;

void batteryTask(void *param){
  while(1){
    if(millis() - last_read > 5000 && read_state == false){
      if(battery.get_percentage() > 60){
        lcd.showBattery(BATTERY_FULL);
      } else if(battery.get_percentage() <= 60 && battery.get_percentage() > 20){
        lcd.showBattery(BATTERY_HALF);
      } else{
        lcd.showBattery(BATTERY_LOW);
      }
      Serial.println(battery.get_percentage());
      Serial.println(battery.get_voltage());
      Serial.println(analogReadMilliVolts(36));
      Serial.println(analogRead(36));
      last_read = millis();
    }

    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

void mainTask(void *param){
  while(1){
    if(digitalRead(14)){
      read_state = true;
      
      lcd.reset();
      float dumpTEMP = 0.0, temp_now;
      int dumpBPM = 0, dumpSPO = 0, bpm_now, n = 0, spo_now;
      
      lcd.notice("BPM", "Posisikan jari pada sensor");
      delay(1000);
      bpm.start();
      for(int i = 0; i <= 2500; i++){
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
        Serial.println("scan...");
        lcd.load( i / 250 );
        delay(1);
      }

      bpm.stop();

      lcd.notice("TENSI", "Kencangkan pad pada lengan");
      delay(2000);
      int adc0 = 0, sis = 0, dis = 0, mmhg = 0, lastmmhg = 0, mark = 0, adc1 = 0;
          
      motor.start();
      mmhg = pressure.mmhg();
      lcd.load(2);
      while(mmhg < 300){
        mmhg = pressure.mmhg();
        
        Serial.print("Pressure : ");
        Serial.print(mmhg);
        Serial.println(" mmhg");
        
        if(mmhg == lastmmhg){
          mark++;
          Serial.println("Mark : " + String(mark));
        } else{
          mark = 0;
        }

        if(mark > 10){
          break;
        }
        
        lastmmhg = mmhg;
        
        delay(50);
      }
      delay(200);

      mark = 0;

      motor.pause();
      lcd.load(7);

      while(mmhg > 50){
        mmhg = pressure.mmhg();

        Serial.print("Pressure : ");
        Serial.print(mmhg);
        Serial.println(" mmhg");

        if(lastmmhg <= mmhg){ //deteksi detak jantung
          if(mark==0){
            mark=1;
          } else if(mark==1){
            sis=mmhg;
            mark=2;
            mark++;
          } else if(mark>1){
            mark++;
            dis=mmhg;
          }
          Serial.print(sis);
          Serial.print("-");
          Serial.print(dis);
          Serial.print("-");
          Serial.println(mark);
          delay(100);
        }

        if(mark>10) break;
        
        lastmmhg = mmhg;
        delay(100);
      }

      motor.stop();
      delay(1000);
      lcd.load(10);
      delay(2000);
      sis *= 0.95;  //kalibrasi sistol, nilai sistol = sistol x 0,95
      dis *= 0.85;  //kalibrasi diastol, nilai diastol = diastol x 0,85
      
      // save data
      String s1 = String(bpm_now);// + " bpm";
      String s2 = String(spo_now);// + " %";
      String s3 = String(temp_now, 1);// + " *C";
      String s4 = String(sis);
      String s5 = String(dis);
      
      data.save("bpm", s1);
      data.save("spo", s2);
      data.save("temp", s3);
      data.save("sis", s4);
      data.save("dis", s5);

      lcd.show(s1, s2, s3, s4, s5);
      read_state = false;
    }
    vTaskDelay(1 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.load(2);
  delay(50);
  motor.begin();
  lcd.load(4);
  delay(50);
  battery.begin();
  lcd.load(5);
  delay(50);
  bpm.begin();
  bpm.stop();
  lcd.load(6);
  delay(50);
  pressure.begin();
  lcd.load(8);
  delay(200);
  temp.begin();
  lcd.load(9);
  delay(100);
  pinMode(14, INPUT);
  lcd.load(10);
  delay(100);
  lcd.boot();

  delay(2000);
  lcd.show(data.read("bpm"), data.read("spo"), data.read("temp"), data.read("sis"), data.read("dis"));
  
  xTaskCreate(batteryTask, "Battery Sens Task", 1024, NULL, 3, NULL);
  xTaskCreate(mainTask, "Main Proccess Task", 4096, NULL, 4, NULL);
}

void loop() {}
