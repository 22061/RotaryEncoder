int count = 0;
int rotate_count = 0;
int angle = 0;
int i = 0;

#define PPR 2000  //PPR

void setup()
{
  pinMode(2, INPUT_PULLUP);  //A相
  pinMode(3, INPUT_PULLUP);  //B相

  attachInterrupt(digitalPinToInterrupt(2), encoder_pulse, CHANGE);
  Serial.begin(9600);
}

void loop()
{
  Serial.print(count);
  Serial.print(",");
  Serial.print(rotate_count);  //回転数
  Serial.print(",");
  angle = map(i, -PPR, PPR, -360, 360);
  Serial.print(angle);  //回転した角度
  Serial.println("°");

  delay(20);
}

void encoder_pulse()
{
  if(digitalRead(2) ^ digitalRead(3))
  {
    count++;
    i++;
    if(abs(count) % PPR == 0)
    {
      if(count == 0)
      {
        rotate_count = 0;
      }
      else
      {
        rotate_count++;
      }
      i = 0;
    }
  }
  else
  {
    count--;
    i--;
    if(abs(count) % PPR == 0)
    {
      if(count == 0)
      {
        rotate_count = 0;
      }
      else
      {
        rotate_count--;
      }
      i = 0;
    }
  }
}