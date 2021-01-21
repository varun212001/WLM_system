//www.elegoo.com
//2016.12.9

int adc_id = A0;
int HistoryValue = 0;
char printBuffer[128];
int ledPin = 13;
const int buzzerPin = 8;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(adc_id); // get adc value

  if (((HistoryValue >= value) && ((HistoryValue - value) > 10)) || ((HistoryValue < value) && ((value - HistoryValue) > 10)))
  {
    sprintf(printBuffer, "ADC%d level is %d\n", adc_id, value);
    Serial.print(printBuffer);
    if (value > 280)
    {
      tone(buzzerPin, 100, 1000);
      digitalWrite(ledPin, HIGH);
      delay(100);

      noTone(buzzerPin);
      digitalWrite(ledPin, LOW);
      delay(1000000);
      Serial.println("----------- ALARM ACTIVATED -----------");
    }
    else {
      noTone(buzzerPin);
      digitalWrite(ledPin, LOW);
    }
    HistoryValue = value;
  }
}
