// Wiring / Arduino Code
// Code for sensing a switch status and writing the value to the serial port.

//int switchPin = 4;                       // Switch connected to pin 4
#include <Wire.h>

#define MPU_ADDR 0x68

int16_t accelX, accelY, accelZ;
int16_t gyroX, gyroY, gyroZ;
int16_t magX, magY, magZ;
float Xvalue_accel, Yvalue_accel, Zvalue_accel;
float Xvalue_gyro, Yvalue_gyro, Zvalue_gyro;
float Xvalue_mag, Yvalue_mag, Zvalue_mag;

void setup() {
  //pinMode(switchPin, INPUT);             // Set pin 0 as an input
  Serial.begin(115200);
  Wire.begin();                   // Start serial communication at 9600 bps
}

void loop() {
 
  // Request all sensor data in one transmission
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); // Starting address for accelerometer data
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 24); // Request 14 bytes of data for accelerometer, gyroscope, and magnetometer

  if (Wire.available() >= 24) {
    accelX = Wire.read() << 8 | Wire.read();
    accelY = Wire.read() << 8 | Wire.read();
    accelZ = Wire.read() << 8 | Wire.read();
    gyroX = Wire.read() << 8 | Wire.read();
    gyroY = Wire.read() << 8 | Wire.read();
    gyroZ = Wire.read() << 8 | Wire.read();
    magX = Wire.read() << 8 | Wire.read();
    magY = Wire.read() << 8 | Wire.read();
    magZ = Wire.read() << 8 | Wire.read();

    Xvalue_accel = accelX / 16384.0;
    Yvalue_accel = accelY / 16384.0;
    Zvalue_accel = accelZ / 16384.0;

    Xvalue_gyro = gyroX / 16384.0;
    Yvalue_gyro = gyroY / 16384.0;
    Zvalue_gyro = gyroZ / 16384.0;

    Xvalue_mag = magX / 100.0; // Replace with appropriate scaling factor
    Yvalue_mag = magY / 100.0;
    Zvalue_mag = magZ / 100.0;

    Serial.println("Accelerometer Data:");
    Serial.print("X accel: ");
    Serial.println(Xvalue_accel);
    Serial.print("Y accel: ");
    Serial.println(Yvalue_accel);
    Serial.print("Z accel: ");
    Serial.println(Zvalue_accel);

    Serial.println("Gyroscope Data:");
    Serial.print("X gyro: ");
    Serial.println(Xvalue_gyro);
    Serial.print("Y gyro: ");
    Serial.println(Yvalue_gyro);
    Serial.print("Z gyro: ");
    Serial.println(Zvalue_gyro);

    Serial.println("Magnetometer Data:");
    Serial.print("X mag: ");
    //Serial.println(Xvalue_mag);
    //Serial.print("Y mag: ");
    //Serial.println(Yvalue_mag);
    //Serial.print("Z mag: ");
    //Serial.println(Zvalue_mag);
    

}
}