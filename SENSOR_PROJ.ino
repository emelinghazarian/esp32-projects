#include <Temperature_LM75_Derived.h>
Generic_LM75 LM75;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin();
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Temperature = ");
  Serial.print(LM75.readTemperatureC());
  Serial.println(" C");
  delay(5000 );

}
