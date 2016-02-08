#include "L293D.h"
#include <arduino.h>

L293D::L293D(int E1, int I1, int I2) {
  _E1 = E1;
  _I1 = I1;
  _I2 = I2;
  pinMode(_E1, OUTPUT);
  pinMode(_I1, OUTPUT);
  pinMode(_I2, OUTPUT);
  _deadband = 0; // set default deadband to 0
}

void L293D::setDeadband(byte deadband) {
  _deadband = deadband;
}

void L293D::drive(int motorSpeed) {

  // compare against deadband
  // set direction
  // set pwm

  if (motorSpeed >= 0) {
    _motorDirection = 1;
    _motorSpeed = motorSpeed;
  }
  else {
    _motorDirection = 0;
    _motorSpeed = -motorSpeed;
  }

  if (_motorSpeed < _deadband) {
    digitalWrite(_I1, LOW);
    digitalWrite(_I2, LOW);
    analogWrite(_E1, 0);
    return;
  }

  digitalWrite(_I1, _motorDirection);
  digitalWrite(_I2, !_motorDirection);
  analogWrite(_E1, _motorSpeed);
}
