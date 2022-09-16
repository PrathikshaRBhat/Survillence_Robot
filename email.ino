#include <ESP8266WiFi.h>
#include <EMailSender.h>
#include "Arduino.h"

uint8_t connection_state = 0;
uint16_t reconnect_interval = 10000;

EMailSender emailSend("preethijadavk@gmail.com", "rdqovtnvxlakgmog");

const char* ssid = "Redmi";  // Enter SSID here
const char* password = "Deeksha123";  //Enter Password here

int mail_pin_left = D1;
int mail_pin_right = D2;
int mail_pin_center = D5;

void setup() {
  pinMode(mail_pin_left, INPUT);
  pinMode(mail_pin_right, INPUT);
  pinMode(mail_pin_center, INPUT); 
  Serial.begin(9600);
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  
  }
  
  Serial.println("WiFi connected..!");
  delay(2000);
  
  // 
  
}

void loop() {
  int mail_left  = digitalRead(mail_pin_left);
  delay(10);
  int mail_right  = digitalRead(mail_pin_right);
  delay(10);
  int mail_center  = digitalRead(mail_pin_center);
  delay(10);
  if(mail_left)
  {
    sendmail("Obstacle detected at the left");
  }
  if(mail_right)
  {
    sendmail("Obstacle detected at the right");
  }
  if(mail_center)
  {
    sendmail("Obstacle detected at the center");
  }
  Serial.println(mail_left);
  Serial.println(mail_right);
  Serial.println(mail_center);
  
  delay(10);
}


void sendmail(String msg)
{
  EMailSender::EMailMessage message;
  message.subject = "Alert!";
  message.message = msg;

  EMailSender::Response resp = emailSend.send("preethijadavk@gmail.com", message);

  Serial.println("Sending status: ");

  Serial.println(resp.status);//1
  Serial.println(resp.code);//0
//  int c = resp.status.toInt();
  if(resp.status)
  {

     Serial.print("Mail Sent");
     delay(5000);    
  }
  else
  {

     Serial.println("Error in sending mail, respnse code: ");
     Serial.print(resp.code);
     delay(5000);
  }
  Serial.println(resp.desc);
  
}
