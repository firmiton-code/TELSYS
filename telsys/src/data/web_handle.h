#ifndef Web_handle_h_
#define Web_handle_h_

#include <Arduino.h>

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title> Login Page </title>
  <style>
  Body {
    font-family: Calibri, Helvetica, sans-serif;
    background-color: black;
    padding-left: 50px;
    padding-right: 50px;
  }
  button {
      background-color: #4CAF50;
      width: 100%;
      color: white;
      padding: 15px;
      margin: 10px 0px;
      border: none;
      cursor: pointer;
      border-radius: 7px;
  }
  form {
      border: 5px solid #f1f1f1;
      border-radius: 7px;
  }
  input[type=text], input[type=password], input[type=uid] {
      width: 100%;
      margin: 8px 0;
      padding: 12px 20px;
      display: inline-block;
      border: 2px solid green;
      box-sizing: border-box;
      border-radius: 7px;
  }
  button:hover {
      opacity: 0.8;
  }
  .cancelbtn {
      width: 100%;
      background-color: tomato;
      color: white;
      padding: 15px;
      margin: 10px 0px;
      border: none;
      cursor: pointer;
      border-radius: 7px;   
  }
  .container { 
      padding: 25px;
      padding-left: 75px;
      padding-right: 75px;
      background-color: lightblue;
      border-radius: 1px;
  }
  </style>
  </head><body>
    <center> <h1 style="color:white;"> Input WiFi Credentials </h1> </center>
  <br><br>
  <form action="/get">
    <div class="container">
      <label>SSID : </label>
      <input type="text" placeholder="Enter WiFi SSID" name="ssid" required>
      <label>Password : </label>
      <input type="password" placeholder="Enter Password" name="password" required>
      <label>User ID : </label>
      <input type="uid" placeholder="Enter UID" name="uid" required>
      <button type="submit"> Connect </button>
      <br>
    </div>
  </form>
</body></html>)rawliteral";

#endif // Web_handle_h_