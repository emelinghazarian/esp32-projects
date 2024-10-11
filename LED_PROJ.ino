int led_value;
const byte led_gpio = 23;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_gpio, OUTPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led_gpio, HIGH);  
  led_value = digitalRead(led_gpio);
  Serial.print("LED CONDITION: ");
	Serial.println(led_value);
  delay(2000);                      //2ms delay
  digitalWrite(led_gpio, LOW);  
  led_value = digitalRead(led_gpio);
  Serial.print("LED CONDITION: ");
	Serial.println(led_value);
  delay(2000);    
  

}
