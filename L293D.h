#ifndef L293D_h
#define L293D_h
#include <arduino.h>

class L293D {
  public:
    L293D(int, int, int); // using 2 direction pins + 1 enable pin
    void drive(int);
    void setDeadband(byte);

  private:
    int _E1, _I1, _I2;
    //  int _E2, _I3, _I4;
    byte _motorSpeed;
    byte _deadband;
    boolean _motorDirection;
   };
#endif
