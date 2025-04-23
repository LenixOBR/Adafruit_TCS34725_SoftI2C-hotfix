#include <Adafruit_TCS34725softi2c.h>

#include <SoftwareWire.h>                


/* Code for multiple TCS34725, it can be scaled up */
/*
 Connect the following
 * Sensor A:
    VIN - 3.3V
    GND - GND
    SDA - A0
    SCL - A1
 * Sensor B:
    VIN - 3.3V
    GND - GND
    SDA - A2
    SCL - A3
*/

#define SDA_A A0
#define SCL_A A1
#define SDA_B A2
#define SCL_B A3

Adafruit_TCS34725softi2c tcsA(
  TCS34725_INTEGRATIONTIME_154MS,
  TCS34725_GAIN_4X,
  SDA_A, SCL_A
);
Adafruit_TCS34725softi2c tcsB(
  TCS34725_INTEGRATIONTIME_154MS,
  TCS34725_GAIN_4X,
  SDA_B, SCL_B
);

void setup() {
  Serial.begin(9600);
  tcsA.begin();
  tcsB.begin();
}

void loop() {
  uint16_t r, g, b, c;

  // —— Sensor A ——
  tcsA.getRawData(&r, &g, &b, &c);
  Serial.print("Sensor A -> R: "); Serial.print(r);
  Serial.print(" G: "); Serial.print(g);
  Serial.print(" B: "); Serial.print(b);
  Serial.print(" C: "); Serial.println(c);

  delay(500);

  // —— Sensor B ——

  tcsB.getRawData(&r, &g, &b, &c);
  Serial.print("Sensor B -> R: "); Serial.print(r);
  Serial.print(" G: "); Serial.print(g);
  Serial.print(" B: "); Serial.print(b);
  Serial.print(" C: "); Serial.println(c);


  delay(1000);
}
