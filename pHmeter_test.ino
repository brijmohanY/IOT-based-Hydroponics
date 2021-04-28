unsigned long int avgValue;  //Store the average value of the sensor feedback
float b;
int buf[10],temp;
float comp = 0.00 ;            //deviation componsation may differ from sensor to sensor.


void setup() {
  Serial.begin(9600);

}

void loop() {
    for(int i=0;i<10;i++)       //getting 10 sample values for averaging
  { 
    buf[i]=analogRead(A0);
    delay(10);
  }
  for(int i=0;i<9;i++)        //sorting
  {
    for(int j=i+1;j<10;j++)
    {
      if(buf[i]>buf[j])
      {
        temp=buf[i];
        buf[i]=buf[j];
        buf[j]=temp;
      }
    }
  }
  avgValue=0;
  for(int i=2;i<8;i++)                            //taking 6 center values
    avgValue+=buf[i];
  float phValue=(float)avgValue*5.0/1024/6;     //converting to millivolts
  phValue=3.5*phValue+comp;                          // converting to millivolts and also taking offset value
  
  Serial.print("    pH:");  
  Serial.print(phValue,2);
  Serial.println(" ");
  delay(2000);
}
