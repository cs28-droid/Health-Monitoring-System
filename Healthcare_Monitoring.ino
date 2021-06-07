#include <ThingSpeak.h>

#include <Adafruit_MLX90614.h>

//#include "ThingSpeak.h" //install library for thing speak
#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//ThingSpeak Client creation
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;
unsigned long myChannelNumber = 1408980;
const char * myWriteAPIKey = "P2JFDLFG0WUPP7T4";

String myStatus = "";
 
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
 
double temp_amb;
double temp_obj;
double calibration = 2.36;
 
char auth[] = "REUfpr2NhwxmYmPHxtSE554mBQJHhgDo";    // You should get Auth Token in the Blynk App.
char ssid[] = "hrishi";                       // Your WiFi credentials.
char pass[] = "xmdh0694";
 
void setup()
{
  Serial.begin(9600);
  mlx.begin();         //Initialize MLX90614

//WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);  // Initialize ThingSpeak
  
  Blynk.begin(auth, ssid, pass);
  
  Serial.println("Temperature Sensor MLX90614");
 
  
  Serial.println(" Thermometer");
  
  Serial.print("Initializing");
  
}
 
void loop()
{
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }
  
  //Reading room temperature and object temp
  //for reading Fahrenheit values, use
  //mlx.readAmbientTempF() , mlx.readObjectTempF() )
  Blynk.run();
  temp_amb = mlx.readAmbientTempC();
  temp_obj = mlx.readObjectTempC();
 
  //Serial Monitor
  
  Serial.print("Object temp = ");
  Serial.println(temp_obj);
 
  
  
  Blynk.virtualWrite(V1, temp_amb);
  Blynk.virtualWrite(V2, (temp_obj + calibration));
  
  delay(1000);


  Serial.println(analogRead(A0) - 480);
int pr = analogRead(A0) - 480;
//ThingSpeak.setField(1, temp);
  ThingSpeak.setField(1, (int)temp_obj);
  ThingSpeak.setField(2, pr);

// set the status
  ThingSpeak.setStatus(myStatus);
  
  // write to the ThingSpeak channel
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  
  delay(10);
}
