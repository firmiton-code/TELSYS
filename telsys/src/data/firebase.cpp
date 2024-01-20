#include "firebase.h"

FirebaseClass *firebase_instances;

FirebaseClass::FirebaseClass(){
  firebase_instances = this;
}

void FirebaseClass::begin(String url, String secret){
  config.signer.tokens.legacy_token = secret.c_str();
  config.database_url = url;

  // fbdo.setBSSLBufferSize(4096 /* Rx buffer size in bytes from 512 - 16384 */, 1024 /* Tx buffer size in bytes from 512 - 16384 */);
  Firebase.reconnectNetwork(true);

  Firebase.begin(&config, &auth);

  // Comment or pass false value when WiFi reconnection will control by your code or third party library
}

String FirebaseClass::set(int data, String path){
  if(Firebase.setInt(fbdo, path, data)){
    return "ok";
  } else{
    return fbdo.errorReason().c_str();
  }
}

String FirebaseClass::setString(String data, String path){
  if(Firebase.setString(fbdo, path, data)){
    return "ok";
  } else{
    return fbdo.errorReason().c_str();
  }
}

String FirebaseClass::setFloat(float data, String path){
  if(Firebase.setFloat(fbdo, path, data)){
    return "ok";
  } else{
    return fbdo.errorReason().c_str();
  }
}

int FirebaseClass::get(String path){
  int data;
  Firebase.getInt(fbdo, path);
  data = fbdo.to<int>();
  if(!data){
    Serial.println(fbdo.errorReason().c_str());
    return 0;
  } else {
    return data;
  }
}

String FirebaseClass::getString(String path){
  String data;
  Firebase.getString(fbdo, path);
  data = fbdo.to<String>();
  if(!data){
    return fbdo.errorReason().c_str();
  } else {
    return data;
  }
}

FirebaseClass fb;