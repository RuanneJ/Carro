#include <AFMotor.h> // Biblioteca para controle dos motores
#include <SoftwareSerial.h>
SoftwareSerial bluetooth (A0, A1);


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

char comando;

void setup() {
  Serial.begin(9600);  // Comunicação com o Bluetooth
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor3.setSpeed(150);
  motor4.setSpeed(150);
}

void loop() {
  if (Serial.available()) {
    comando = Serial.read();
    if (comando == 'F') {
      moverFrente();
    } else if (comando == 'B') {
      moverTras();
    } else if (comando == 'L') {
      virarEsquerda();
    } else if (comando == 'R') {
      virarDireita();
    } else if (comando == 'S') {
      parar();
    }
  }
}

void moverFrente() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void moverTras() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void virarEsquerda() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void virarDireita() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void parar() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
