int zm=20;

// VARIÁVEIS DOS MOTORES

int M11 = 48; 
int M12 = 46;
int M21 = 50; 
int M22 = 52;
int M1S = 12;
int M2S = 13;
int spd = 60;

int ch1; // Here's where we'll keep our channel values
int ch3;
int ch2;
int eX;
int eY;

void setup() {

  pinMode(5, INPUT); // Set our input pins as such
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(M11, OUTPUT); 
  pinMode(M12, OUTPUT); 
  pinMode(M21, OUTPUT); 
  pinMode(M22, OUTPUT);   
  pinMode(M1S, OUTPUT); 
  pinMode(M2S, OUTPUT);  
  Serial.begin(9600); // Pour a bowl of Serial

}

void loop() {

  ch1 = pulseIn(5, HIGH, 25000); // Read the pulse width of 
  ch2 = pulseIn(6, HIGH, 25000); // each channel
  ch3 = pulseIn(7, HIGH, 25000);

  Serial.print("Channel 1:"); // Print the value of 
  Serial.println(ch1);        // each channel

  Serial.print("Channel 2:");
  Serial.println(ch2);

  Serial.print("Channel 3:");
  Serial.println(ch3);

  Serial.println();

  delay(100); // I put this here just to make the terminal 
              // window happier

  spd = constrain(map(ch2,1206,1980,0,255),0,255);
  eX = constrain(map(ch1,1050,1860,0,255),0,255);
  eY = constrain(map(ch3,1060,1890,0,255),0,255);

  tabelaD();
  R1();

}

int parar(int spd) { // CONFERIDO 
  
  digitalWrite(M11,LOW);
  digitalWrite(M12,LOW);
  digitalWrite(M21,LOW);
  digitalWrite(M22,LOW);
  analogWrite(M1S,spd);
  analogWrite(M2S,spd);
}

int frente(int spd) { // CONFERIDO 
  
  digitalWrite(M11,HIGH);
  digitalWrite(M12,LOW);
  digitalWrite(M21,HIGH);
  digitalWrite(M22,LOW);
  analogWrite(M1S,spd);
  analogWrite(M2S,spd);
}

int tras(int spd) { // CONFERIDO 
  
  digitalWrite(M11,LOW);
  digitalWrite(M12,HIGH);
  digitalWrite(M21,LOW);
  digitalWrite(M22,HIGH);
  analogWrite(M1S,spd);
  analogWrite(M2S,spd);
}

int esquerda90(int spd) { // UMA RODA É ACIONADA 
  digitalWrite(M11,LOW);
  digitalWrite(M12,HIGH);
  digitalWrite(M21,HIGH);
  digitalWrite(M22,LOW);
  analogWrite(M1S,spd);
  analogWrite(M2S,spd);
}

int direita90(int spd) { // UMA RODA É ACIONADA 
  digitalWrite(M11,HIGH);
  digitalWrite(M12,LOW);
  digitalWrite(M21,LOW);
  digitalWrite(M22,HIGH);
  analogWrite(M1S,spd);
  analogWrite(M2S,spd);
}

int direita(int spd) { // UMA RODA É ACIONADA 
  digitalWrite(M11,HIGH);
  digitalWrite(M12,LOW);
  digitalWrite(M21,HIGH);
  digitalWrite(M22,LOW);
  analogWrite(M1S,spd);
  analogWrite(M2S,0);
}

void esquerda(int spd) { // UMA RODA É ACIONADA 
  digitalWrite(M11,HIGH);
  digitalWrite(M12,LOW);
  digitalWrite(M21,HIGH);
  digitalWrite(M22,LOW);
  analogWrite(M1S,0);
  analogWrite(M2S,spd);
}
void tabelaD(){

  //FRENTE
  
  if(eY > 127-zm && eX <127+zm && eX > 127-zm){
    tras(spd);
  }

  if(eY < 127+zm && eX <127+zm && eX > 127-zm){
    frente(spd);
  }

  if(eX < 127+zm && eY <127+zm && eY > 127-zm){
    esquerda90(spd);
  }

  if(eX > 127-zm && eY <127+zm && eY > 127-zm){
    direita90(spd);
  }

  if(eY < 127+zm && eY > 127-zm && eX <127+zm && eX > 127-zm){
    parar(spd);
  }
}

