//initializes/defines the output pin of the LM335 temperature sensor
int sensor_one = 14;
int sensor_two = 15;
int desired_temperature = 30;
int output[2] = {3,2};
//this sets the ground pin to LOW and the input voltage pin to high
void setup()
{
Serial.begin(9600);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
}

float getTemperature(int reading)
{
  float milivolts = (reading/1024.0)*5000;
  return milivolts/10 - 273.15;
}

void turn_all_on()
{
  int i =0;
  for(i = 0; i < 2; i++)
  {
    digitalWrite(output[i],HIGH);
  }
}
void turn_all_off()
{
  int i =0;
  for(i = 0; i < 2; i++)
  {
    digitalWrite(output[i],LOW);
  }
}

void turn_one_on(int one)
{
  digitalWrite(one,HIGH);
}
void turn_one_off(int one)
{
  digitalWrite(one,LOW);
}




//main loop
void loop()
{
  delay(5000);
int reading_one = analogRead(sensor_one);
int reading_two = analogRead(sensor_two);

float temperature_one = getTemperature(reading_one);
float temperature_two = getTemperature(reading_two);
Serial.print(temperature_one);
Serial.print(" ");
Serial.print(temperature_two);

float average_temperature = (temperature_one + temperature_two) / 2;

Serial.print(" ");
Serial.print(average_temperature);

if(average_temperature < desired_temperature)
{
  turn_all_on();
  Serial.println("Turned both");
  return;
  
} else if(temperature_one < desired_temperature)
{
  turn_one_on(3);
  Serial.println("Turned one");
  return;
}else if(temperature_two < desired_temperature)
{
  turn_one_on(2);
  Serial.println("Turned two");
  return;
}
else {
turn_all_off();
Serial.println("Turned none");
}
}




