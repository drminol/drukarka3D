// Piny
#define X_MIN_PIN           3
#ifndef X_MAX_PIN
#define X_MAX_PIN           2
#endif
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

// Silniki
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_CS_PIN           53

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_CS_PIN           49

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_CS_PIN           40

#define E0_STEP_PIN        26
#define E0_DIR_PIN         28
#define E0_ENABLE_PIN      24
#define E0_CS_PIN          42


// Inicjalizacja zmiennych
int buttonX;
int buttonY;
int buttonZ;

int krokiX = 0;
int krokiY = 0;
int krokiZ = 0;
int kX;
int kY;
int kZ;
String a;

void setup() {

  // Otwarcie portu szeregowego
  Serial.begin(57600);

  // Zmniejszenie czasu oczekiwania
  Serial.setTimeout(50); 

  // Krancowki
  pinMode(X_MAX_PIN, INPUT);
  digitalWrite(X_MAX_PIN, HIGH);
  pinMode(Y_MAX_PIN, INPUT);
  digitalWrite(Y_MAX_PIN, HIGH);
  pinMode(Z_MAX_PIN, INPUT);
  digitalWrite(Z_MAX_PIN, HIGH);

  // Silnik X
  pinMode(X_STEP_PIN, OUTPUT);
  digitalWrite(X_STEP_PIN, HIGH);
  pinMode(X_DIR_PIN, OUTPUT);
  digitalWrite(X_DIR_PIN, LOW);
  pinMode(X_ENABLE_PIN, OUTPUT);
  digitalWrite(X_ENABLE_PIN, LOW);
  pinMode(X_CS_PIN, OUTPUT);
  digitalWrite(X_CS_PIN, HIGH);

  // Silnik Y
  pinMode(Y_STEP_PIN, OUTPUT);
  digitalWrite(Y_STEP_PIN, HIGH);
  pinMode(Y_DIR_PIN, OUTPUT);
  digitalWrite(Y_DIR_PIN, LOW);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  digitalWrite(Y_ENABLE_PIN, LOW);
  pinMode(Y_CS_PIN, OUTPUT);
  digitalWrite(Y_CS_PIN, HIGH);

    // Silnik Z
  pinMode(Z_STEP_PIN, OUTPUT);
  digitalWrite(Z_STEP_PIN, HIGH);
  pinMode(Z_DIR_PIN, OUTPUT);
  digitalWrite(Z_DIR_PIN, LOW);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  digitalWrite(Z_ENABLE_PIN, LOW);
  pinMode(Z_CS_PIN, OUTPUT);
  digitalWrite(Z_CS_PIN, HIGH);

//  // Silnik E0
//  pinMode(X_MAX_PIN, INPUT);
//  digitalWrite(X_MAX_PIN, HIGH);
//  pinMode(Y_MAX_PIN, INPUT);
//  digitalWrite(Y_MAX_PIN, HIGH);
//  pinMode(Z_MAX_PIN, INPUT);
//  digitalWrite(Z_MAX_PIN, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  buttonX = digitalRead(X_MAX_PIN);
  buttonY = digitalRead(Y_MAX_PIN);
  buttonZ = digitalRead(Z_MAX_PIN);

while(Serial.available())
{
  a = Serial.readString();
  Serial.print(a);

 sscanf(a.c_str(),"x %d y %d z %d",&krokiX,&krokiY,&krokiZ);

// Realizacja krokow
 if(krokiX<0)
 {
  krokiX*=-1;
  digitalWrite(X_DIR_PIN, HIGH);
  }
  else
  digitalWrite(X_DIR_PIN, LOW);

   if(krokiY<0)
 {
  krokiY*=-1;
  digitalWrite(Y_DIR_PIN, HIGH);
  }
  else
  digitalWrite(Y_DIR_PIN, LOW);

   if(krokiZ<0)
 {
  krokiZ*=-1;
  digitalWrite(Z_DIR_PIN, HIGH);
  }
  else
  digitalWrite(Z_DIR_PIN, LOW);
  
    Serial.print(krokiX);
    Serial.print(krokiY);
    Serial.println(krokiZ);
  }
  // Realizacja ruchu
  if(buttonX == 0 && krokiX > 0)
    {
      digitalWrite(X_STEP_PIN, HIGH);
      krokiX = krokiX - 1;   
    }
    else if(buttonX == 1 && krokiX > 0)
    {
      digitalWrite(X_DIR_PIN, HIGH);
      digitalWrite(X_STEP_PIN, HIGH);
      krokiX = 1000; 
      }
      
  if(buttonY == 0 && krokiY > 0)
    {
      digitalWrite(Y_STEP_PIN, HIGH);
      krokiY = krokiY - 1;
    } 
    else if(buttonY == 1 && krokiY > 0)
    {
      digitalWrite(Y_DIR_PIN, HIGH);
      digitalWrite(Y_STEP_PIN, HIGH);
      krokiY = 1000; 
      }
  if(buttonZ == 0 && krokiZ > 0) 
    {
      digitalWrite(Z_STEP_PIN, HIGH);
      krokiZ = krokiZ - 1;
    }
    else if(buttonZ == 1 && krokiZ > 0)
    {
      digitalWrite(Z_DIR_PIN, HIGH);
      digitalWrite(Z_STEP_PIN, HIGH);
      krokiZ = 1000; 
    }

  // Opoznienie
  delayMicroseconds(70);

  // Wystawienie zer na piny zwiazane z poruszaniem silnikami
  digitalWrite(X_STEP_PIN, LOW);   
  digitalWrite(Y_STEP_PIN, LOW);   
  digitalWrite(Z_STEP_PIN, LOW);

  // Opoznienie
  delayMicroseconds(70);


}

