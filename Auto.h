#ifndef _Auto_H_
#define _Auto_H_

// Auto.h
#include "Person.h"

class Auto
{
private:
protected:
public:
  int numWheels, totalRiders, autoWeight, speed;
  int autoSize; //1 = small (motorcycle), 2 = medium (i.e. regular car), 3 = large (i.e. minivans), 4 = extra large (i.e. trucks)
  string primaryColor, secondaryColor;
  bool autoIsInDanger;

  //TODO: Any functions below
  int getTotalSurvivalChance(); //Combined survival chance of every person in Vehicle

  Auto(int, int, int, int, int, string, string, bool);
  Auto();
};

#endif /* _Auto_H_ */