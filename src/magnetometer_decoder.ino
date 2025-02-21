#include <Wire.h>
#include <QMC5883LCompass.h>

#define TCA9548A_ADDRESS 0x70  // I2C address of the TCA9548A multiplexer

QMC5883LCompass compass;

void setup() {
  Serial.begin(230400);

  // Initialize I2C bus for ESP32
  Wire.begin(21, 22);  // SDA = GPIO 21, SCL = GPIO 22 for ESP32
}

void selectMultiplexerChannel(uint8_t channel) {
  Wire.beginTransmission(TCA9548A_ADDRESS);
  Wire.write(1 << channel);  // Select the specified channel on the TCA9548A
  Wire.endTransmission();
}

int readCompass(QMC5883LCompass &compass, const char* label) {
    compass.init();

    int x, y, z, azimuth, bearing;
    compass.read();
    x = compass.getX();
    y = compass.getY();
    z = compass.getZ();
    azimuth = compass.getAzimuth();
    bearing = compass.getBearing(azimuth);
    //compass.getDirection(direction, azimuth);

    // Ensure the direction string is null-terminated
    return bearing;

    
}

void loop() {

    // Select and read from the first compass (Channel 0)
    selectMultiplexerChannel(0);
    int d1 = readCompass(compass, "Compass 1");

    
    // Select and read from the second compass (Channel 1)
    selectMultiplexerChannel(1);
    int d2 = readCompass(compass, "Compass 2");

   
    if ((d1 == 14 && d2 == 6) ||(d1 == 14 && d2 == 5)) {
        Serial.println("Base");
    } 
    else if( d1 == 14 && d2 == 7){
      Serial.println("I love you");
    }
    else if((d1 == 0 && d2 == 6)||(d1 == 1 && d2 == 6)){
      Serial.println("Yes");
    }
    else if((d1 == 10 && d2 == 2) ){
      Serial.println("Please");
    }
    else if((d1 == 5 && d2 == 3)||(d1 == 5 && d2 == 4)){
      Serial.println("Help");
    }
    else if( d1 == 15 && d2 == 6){
      Serial.println("You");
    }
    else if((d1 == 13 && d2 == 10)||(d1 == 13 && d2 == 9) ){
      Serial.println("I hate you");
    }
    else if((d1 == 15  && d2 == 4)||(d1 == 15  && d2 == 5) ){
      Serial.println("Calm");
    }
    else if((d1 == 8 && d2 == 2) ){
      Serial.println("Sorry");
    }
    else if((d1 == 13 && d2 == 7)||(d1 == 13 && d2 == 8)){
      Serial.println("Hi");
    }
    else if((d1 == 13 && d2 == 2) ){
      Serial.println("Pray");
    }
    else if((d1 == 12 && d2 == 1) ){
      Serial.println("Go straight");
    }
    else if( (d1 == 15 && d2 == 3) || (d1 == 14 && d2 == 3)){
      Serial.println("Father");
    }
    else if((d1 == 13 && d2 == 1)||(d1 == 13 && d2 == 0)){
      Serial.println("C");
    }
    else if((d1 == 2 && d2 == 4)||(d1 == 1 && d2 == 4) ){
      Serial.println("Ok");
    }
    else if((d1 == 11 && d2 == 0)||(d1 == 10 && d2 == 0)){
      Serial.println("Read");
    }
    else {
        Serial.println("Try again");
    }
    delay(4000);//for matching with pyttsx3
}
