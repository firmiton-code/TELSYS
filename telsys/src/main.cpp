#include <Arduino.h>
#include "device_config.h"

bool read_state = false;
bool lcd_state = true;
bool connection_state = false;
bool new_data = false;
unsigned long last_read = 0;

float dumpTEMP = 0.0, temp_now;
int dumpBPM = 0, dumpSPO = 0, bpm_now, n = 0, spo_now;
int adc0 = 0, sis = 0, dis = 0, mmhg = 0, lastmmhg = 0, mark = 0, adc1 = 0;
String path[6], data1, data2, data3, data4, data5;

void blood_test(){
        
  motor.start();
  mmhg = 0;
  lcd.load(2);
  while(mmhg < 500){
    if(pressure.ready()){
      mmhg = pressure.get()+350;
      // if(mmhg < 0) mmhg = 0;

      Serial.print("Pressure : ");
      Serial.print(mmhg);
      Serial.println(" mmhg");
      
      if(mmhg == lastmmhg){
        mark++;
        Serial.println("Mark : " + String(mark));
      } else{
        mark = 0;
      }

      if(mark > 5){
        break;
      }
      
      lastmmhg = mmhg;
    }  
    
    delay(50);
  }
  delay(200);

  mark = 0;

  motor.pause();
  lcd.load(7);

  while(mmhg > 50){
    if(pressure.ready()){
      mmhg = pressure.get()+350;

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
}

void scan_temp(){
  float tempSens = temp.temperature() + 2.5;
  int n2 = 0;
  float dumpTemp = 0.00;
  for(int i = 0; i <= 2500; i++){    
    tempSens = temp.temperature() + 2.5;
    if (tempSens >= 34.0 && tempSens <= 45.0) { //batas rata2 pengukuran
      dumpTemp += tempSens;
      n2++;

      temp_now = dumpTemp / n2;       //kalibrasi bpm
    }
    Serial.println("scan...");
    lcd.load( i / 250 );
    delay(1);
  }
  if(temp_now >= 30.0 && temp_now <= 50.0) temp_now = temp_now * 1.0;     //kalibrasi suhu
  else temp_now = 0;
}

void scan_finger(){
  bpm.start();
  dumpBPM = 0; dumpSPO = 0; bpm_now = 0; n = 0; spo_now = 0;
  for(int i = 0; i <= 2500; i++){
    bpm.update();
    int bpmSens = bpm.bpm() + 15;
    int spoSens = bpm.spo2();
    
    if (bpmSens >= 40.0 && bpmSens <= 200.0 && spoSens >= 80 && spoSens <= 100/* && tempSens >= 34.0 && tempSens <= 45.0*/) { //batas rata2 pengukuran
      dumpBPM += bpmSens;
      dumpSPO += spoSens;
      n++;

      bpm_now = dumpBPM / n;       //kalibrasi bpm
      spo_now = dumpSPO / n;        //kalibrasi spo
    }
    Serial.println("scan...");
    lcd.load( i / 250 );
    delay(1);
  }

  bpm.stop();
}

void batteryUpdate(){
  if(millis() - last_read > 5000 && read_state == false){
    if(battery.get_percentage() > 60){
      lcd.showBattery(BATTERY_FULL);
    } else if(battery.get_percentage() <= 60 && battery.get_percentage() > 20){
      lcd.showBattery(BATTERY_HALF);
    } else{
      lcd.showBattery(BATTERY_LOW);
    }
    debugVal("MAIN", "Battery : ",battery.get_percentage());
    debugVal("MAIN", "Battery : ",battery.get_voltage());
    Serial.println(analogReadMilliVolts(36));
    Serial.println(analogRead(36));
    last_read = millis();
  }
}

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.load(1);
  unsigned long time_now = millis();
  net.connect(data.read("ssid"), data.read("pass"));
  int connect_chances = 10;
  while (!net.get_status()){
    if(millis() - time_now > 1000){
      Serial.print(".");
      connect_chances--;
      debug("WIFI", connect_chances);
      if(connect_chances < 1) {
        data.format();
        break;
      }

      time_now = millis();
    }
  }
  
  if(!net.get_status()) lcd.show_choose();
  else {
    net.begin();
    fb.begin(FIREBASE_HOST, FIREBASE_AUTH);
    connection_state = true;
  }

  while(!net.get_status()){
    if(lcd.touchUpdate()){
      if(lcd.getConnection()){
        net.begin();
        connection_state = true;
        fb.begin(FIREBASE_HOST, FIREBASE_AUTH);
        break;
      } 
      
      if(lcd.getOffline()){
        connection_state = false;
        break;
      }
    }
  }
  
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
  delay(50);
  pressure.start();
  lcd.load(6);
  delay(100);
  lcd.load(8);
  delay(200);
  temp.begin();
  lcd.load(9);
  delay(100);
  pinMode(27, INPUT_PULLDOWN);
  pinMode(12, OUTPUT);
  lcd.load(10);
  delay(100);
  lcd.boot();

  delay(2000);
  lcd.show(data.read("bpm"), data.read("spo"), data.read("temp"), data.read("sis"), data.read("dis")); batteryUpdate();
}

void loop() {
  if(lcd.touchUpdate() || digitalRead(27)){
    if(lcd_state && lcd.getPlay()){
      read_state = true;
    } 
    
    if(lcd.getPower()){
      debug("Touch", "Button Power Press");
      esp_sleep_enable_ext0_wakeup(GPIO_NUM_14, 0);
      delay(500);
      // ESP.restart();
      esp_deep_sleep_start();
    }
    
    if(lcd_state == false){
      lcd_state = true;
      last_read = millis();
    }

    if(lcd.getScreen() == MAIN_SCREEN){
      if(lcd.getHRButton() || lcd.getSPO2Button()){
        lcd.reset();
    
        lcd.notice("BPM", "Posisikan jari pada sensor");
        delay(2000);

        scan_finger();
        
        String s1 = String(bpm_now);// + " bpm";
        String s2 = String(spo_now);// + " %";
        
        Serial.println(s1);
        Serial.println(s2);

        data.save("bpm", s1);
        data.save("spo", s2);

        lcd.show(s1, s2, data.read("temp"), data.read("sis"), data.read("dis"));

        if(connection_state){
          path[0] = "Data/" + net.get_uid() + "/Hasil Pengukuran/" + ntp.get_raw_epoch() + "/BPM";
          path[1] = "Data/" + net.get_uid() + "/Hasil Pengukuran/" + ntp.get_raw_epoch() + "/Oxygen";
          debugVal("UPLOAD", "Status...", fb.setString(s1, path[0]));
          debugVal("UPLOAD", "Status...", fb.setString(s2, path[1]));
          debug("TIME", ntp.get_time());
        }

        read_state = false;
        lcd.setPlay(read_state);
        last_read = millis();
      } 
      
      if(lcd.getTempButton()){
        lcd.reset();
    
        lcd.notice("BPM", "Posisikan jari pada sensor");
        delay(2000);

        scan_temp();
        
        delay(2000);

        String s3 = String(temp_now, 1);// + " *C";
        
        Serial.println(s3);
        
        data.save("temp", s3);
        
        lcd.show(data.read("bpm"), data.read("spo"), s3, data.read("sis"), data.read("dis"));

        if(connection_state){
          path[2] = "Data/" + net.get_uid() + "/Hasil Pengukuran/" + ntp.get_raw_epoch() + "/Sistole";
          debugVal("UPLOAD", "Status...", fb.setString(s3, path[2]));
          debug("TIME", ntp.get_time());
        }
      }
      
      if(lcd.getBPButton()){
        lcd.reset();

        lcd.notice("TENSI", "Kencangkan pad pada lengan");
        delay(2000);
        
        blood_test();
        
        // sis = random(100, 140);
        // dis = random(60, 100);

        // save data
        String s4 = String(sis);
        String s5 = String(dis);
        
        Serial.println(s4);
        Serial.println(s5);

        data.save("sis", s4);
        data.save("dis", s5);
        
        lcd.show(data.read("bpm"), data.read("spo"), data.read("temp"), s4, s5);
        
        if(connection_state){
          path[3] = "Data/" + net.get_uid() + "/Hasil Pengukuran/" + ntp.get_raw_epoch() + "/Diastole";
          path[4] = "Data/" + net.get_uid() + "/Hasil Pengukuran/" + ntp.get_raw_epoch() + "/Suhu";
          debugVal("UPLOAD", "Status...", fb.setString(s4, path[3]));
          debugVal("UPLOAD", "Status...", fb.setString(s5, path[4]));
          debug("TIME", ntp.get_time());
        }

        read_state = false;
        lcd.setPlay(read_state);
        last_read = millis();
      }
    }
  }

  if(millis() - last_read > 30000 && lcd_state){
    lcd_state = false;
    last_read = millis();
  }

  if(lcd_state){
    digitalWrite(12, HIGH);
  } else{
    digitalWrite(12, LOW);
  }

  if(read_state){
    lcd.reset();
    
    lcd.notice("BPM", "Posisikan jari pada sensor");
    delay(2000);

    scan_finger();

    // while(bpm_now < 300 || bpm_now > 0){
    //   lcd.notice("BPM", "Posisikan kembali jari");
    //   delay(1000);
    //   scan_finger();
    // }
    scan_temp();
    
    lcd.notice("TENSI", "Kencangkan pad pada lengan");
    delay(2000);
    
    blood_test();
    
    // sis = random(100, 140);
    // dis = random(60, 100);

    // save data
    String s1 = String(bpm_now);// + " bpm";
    String s2 = String(spo_now);// + " %";
    String s3 = String(temp_now, 1);// + " *C";
    String s4 = String(sis);
    String s5 = String(dis);
    
    Serial.println(s1);
    Serial.println(s2);
    Serial.println(s3);
    Serial.println(s4);
    Serial.println(s5);

    data.save("bpm", s1);
    data.save("spo", s2);
    data.save("temp", s3);
    data.save("sis", s4);
    data.save("dis", s5);

    lcd.show(s1, s2, s3, s4, s5);

    if(connection_state){
      path[0] = "Data/" + net.get_uid() + "/Hasil Pengukuran/" + ntp.get_raw_epoch() + "/BPM";
      path[1] = "Data/" + net.get_uid() + "/Hasil Pengukuran/" + ntp.get_raw_epoch() + "/Oxygen";
      path[2] = "Data/" + net.get_uid() + "/Hasil Pengukuran/" + ntp.get_raw_epoch() + "/Sistole";
      path[3] = "Data/" + net.get_uid() + "/Hasil Pengukuran/" + ntp.get_raw_epoch() + "/Diastole";
      path[4] = "Data/" + net.get_uid() + "/Hasil Pengukuran/" + ntp.get_raw_epoch() + "/Suhu";
      
      debugVal("UPLOAD", "Status...", fb.setString(s1, path[0]));
      debugVal("UPLOAD", "Status...", fb.setString(s2, path[1]));
      debugVal("UPLOAD", "Status...", fb.setString(s3, path[2]));
      debugVal("UPLOAD", "Status...", fb.setString(s4, path[3]));
      debugVal("UPLOAD", "Status...", fb.setString(s5, path[4]));

      debug("TIME", ntp.get_time());
    }

    read_state = false;
    lcd.setPlay(read_state);
    last_read = millis();
  }
  
  batteryUpdate();

  delay(100);
}
