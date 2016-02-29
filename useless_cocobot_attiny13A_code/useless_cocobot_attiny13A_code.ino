int sv = 0;
int sw = 1;
int pv = 0;
byte s = 0;

void setup() {
  pinMode(s, OUTPUT);
  pinMode(sw, INPUT);
}

void loop() {
  sv = digitalRead(sw);
  if (pv != sv){
    if (sv == 0){
     for (byte pos=0;pos<90;pos++){
        pulseOut(s,pos);        
      }
    }else{
      for (byte pos=90;pos>0;pos--){
        pulseOut(s,pos);        
      }
    }
    pv = sv;
  }
  delay(100);
}

void pulseOut( byte pin, byte p){
  digitalWrite(pin,HIGH);
  delayMicroseconds(300+p*(2500/180));
  digitalWrite(pin,LOW);
  //Serial.println(p*(1000/180));
}
