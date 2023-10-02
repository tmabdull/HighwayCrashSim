#ifndef _Motorcycle_H_
#define _Motorcycle_H_

// Motorcycle.h
#include "Auto.h"

class Motorcycle : public Auto
{
private:
protected:
public:
  string Make, Model;

  Motorcycle(string, string, int, int, int);
  Motorcycle();

  //TODO: All of these
  int getNumPeople();
  int randChoiceHit();          //choose which motorcycle to hit
  int communicateDanger();      //return 0 if a vehicle is safe from the Motorcycle, 1 if the vehicle is not safe from the Motorcycle
  void calcWithHighestChance(); //Compare survival chance of different motorcycle riders, select one with highest chance
  void hit();                   //Hit the chosen vehicle

  //TODO: These JSON functions need to call the functions from Auto
  virtual Json::Value dump2JSON(); // print the content of the object
  virtual bool JSON2Object(Json::Value);
};

#endif /* _Motorcycle_H_ */