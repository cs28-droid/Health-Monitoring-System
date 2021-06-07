# Health-Monitoring-System

--ABSTRACT--

COVID-19 is a pandemic extending beyond its biological scale to infect lives globally. This menace has claimed innumerable lives with no possible cure in sight. However, we can try to reduce the effects of this pandemic by following social distancing norms. There are many patients who have recovered from this deadly virus and need to be monitored constantly even when they are at home. IoT (Internet of things) plays a vital role in health systems that help to monitor patient’s health conditions. This project describes the construction and design of a simple low cost IoT and GSM based healthcare monitoring system at home. This framework consists of various smart sensors like pulse oximeter heart rate sensor (MAX30100) to measure patients SPO2 and pulse reading, IR temperature sensor (MLX90614) to measure body temperature and also equipped with a GSM module to send SMS (short message service) to doctors when body vitals are above or below normal level so that the doctors can take emergency measures immediately. The system is also equipped with a ventilator for use in emergency purposes when the patient's SPO2 levels are low. This can be used without any medical help. This system uses NodeMCU as a microcontroller board with Google Firebase as an online database to keep a track of patient’s vitals on a real-time basis. These data can be later accessed by doctors through laptops and smartphones. This system will help bridge gaps between the patients and doctors during the pandemic situation.

--INTRODUCTION--

IoT is a network of physical devices that uses connectivity to enable the exchange of data. IoT has many applications like smart cities, home automation, remote healthcare monitoring, smart agriculture and many more. The current dire situation faced by the world is the COVID-19 pandemic. COVID, also known as Coronavirus Disease, is a virus that affects people by infecting their lungs and causing trouble in breathing. Many people have been infected by this deadly virus. Also, many people have recovered from this disease and are sent back home. But their body vitals still need to be monitored constantly under surveillance as their body would be weak.
To help the post-covid patients, we have combined IoT with healthcare sensors and GSM modules to keep a track of patients remotely. This system is a low-cost system that is embedded with various sensors like SPO2, pulse and temperature. These vitals are tracked every hour and are stored on the cloud working on a real-time basis. The GSM module is provided to alert the doctors in-charge of their patients if the patient's vitals are unstable. The healthcare system works better and more suitable by integrating both IoT and GSM together for patient monitoring.

#HARDWARE COMPONENTS:

NodeMCU
MAX30100 pulse oximeter sensor
MLX90614 IR temperature sensor
16x2 LCD display
12V 90rpm DC motors
Single channel relay
128x64 OLED display
Potentiometers
GSM900 module
Wi-Fi module
3.3V logic converter
Ambu Bag

#SOFTWARE AND TOOLS:

Arduino IDE
IFTTT
Thingspeak
Eagle



