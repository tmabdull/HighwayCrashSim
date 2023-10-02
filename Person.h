
#ifndef _PERSON_H_
#define _PERSON_H_

// Person.h

#include "JvTime.h"

class Person
{
private:
public:
  string name;
  int size, weight, age, survivalChance;
  bool hasWindshield, hasHelmet;
  Person(string, int, int, int, bool, bool);
  Person();

  bool operator==(Person& aPerson);
  string getName();

  int calcSurvivalChance(); //TODO: See Person.cpp
  
  virtual Json::Value dump2JSON();
  virtual bool JSON2Object(Json::Value);
};

#endif  /* _PERSON_H_ */
