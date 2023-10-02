#ifndef _Car_H_
#define _Car_H_

// Car.h
#include "Auto.h"

class Car : public Auto
{
private:
protected:
public:
  string Make, Model;
  //TODO: Has a Person  rider and Person passenger(s)

  Car(string, string, int, int, int);
  Car();

  //TODO: All of these
  int getNumPeople();
  int randChoiceHit();          //choose which motorcycle to hit
  int communicateDanger();      //return 0 if a vehicle is safe from the car, 1 if the vehicle is not safe from the car
  void calcWithHighestChance(); //Compare survival chance of different motorcycle riders, select one with highest chance
  void hit();                   //Hit the chosen vehicle

  //TODO: These JSON functions need to call the functions from Auto
  virtual Json::Value dump2JSON(); // print the content of the object
  virtual bool JSON2Object(Json::Value);
};

#endif /* _Car_H_ */