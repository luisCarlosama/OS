// Sketch C++

/*
    Developer: Anderson
    Sketch description: Control de motor y LED según temperatura
*/

int const LED1 = 13;  
int const MOT = 12;   
int sensorValue;    
float temp;         

void setup() {
  pinMode(LED1, OUTPUT);  
  pinMode(MOT, OUTPUT);   
  Serial.begin(9600);     
  Serial.println("### Temperature monitor ###");
}

void loop() {
  sensorValue = analogRead(A0);  
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  delay(2000); 

  // Convertimos el valor del sensor en temperatura (en grados Celsius)
  temp = (sensorValue * 5.0) / 1024.0 * 100.0;
  Serial.print("Temp value: ");
  Serial.println(temp);
  delay(2000);  // Espera de 2 segundos

  // Validación 1: Si la temperatura es inferior a 5°C, el LED parpadea con retardo de 0.5 segundos
  if (temp < 5) {
    digitalWrite(MOT, LOW);  
    while (true) {
      digitalWrite(LED1, HIGH);  
      delay(500);  
      digitalWrite(LED1, LOW);   
      delay(500);  
      // Salir del bucle cuando la temperatura suba
      sensorValue = analogRead(A0);  
      temp = (sensorValue * 5.0) / 1024.0 * 100.0;
      if (temp >= 5) break;  
    }
  }
  
  // Validación 2: Si la temperatura está entre 6°C y 25°C, apaga el LED (sin intermitencia)
  else if (temp >= 6 && temp <= 25) {
    digitalWrite(LED1, LOW);  
    digitalWrite(MOT, LOW);   
  }

  // Validación 3: Si la temperatura es mayor a 25°C, enciende el LED y el motor
  else if (temp > 25) {
    digitalWrite(LED1, HIGH);  
    digitalWrite(MOT, HIGH);   
    Serial.println("Motor ON");
  }

  delay(2000);  
}