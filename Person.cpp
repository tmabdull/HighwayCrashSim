
#include "Person.h"

Person::Person(string arg_name, int arg_size, int arg_weight, int arg_age, bool arg_hasWindshield, bool arg_hasHelmet)
{
  this->name = arg_name;
  this->size = arg_size;
  this->weight = arg_weight;
  this->age = arg_age;
  this->hasWindshield = arg_hasWindshield;
  this->hasHelmet = arg_hasHelmet;
}

Person::Person()
{
  this->name = "";
  this->size = 0;
  this->weight = 0;
  this->age = 0;
  this->hasWindshield = false;
  this->hasHelmet = false;
}

std::string Person::getName()
{
  return this->name;
}

int calcSurvivalChance() //TODO: Use all of the ints to assign a survival score/chance in the event of a crash
{
  return 0;
}

Json::Value Person::dump2JSON(void)
{
  Json::Value result { };

  if (this->name != "")
  {
    result["name"] = this->name;
  }
  if (this->size != 0)
  {
    result["size"] = this->size;
  }
  if (this->weight != 0)
  {
    result["weight"] = this->weight;
  }
  if (this->age != 0)
  {
    result["age"] = this->age;
  }
  
  result["hasWindshield"] = hasWindshield;
  result["hasHelmet"] = hasHelmet;
  

  return result;
}


bool Person::JSON2Object(Json::Value arg_person) {
  this->name = (arg_person["name"]).asString();
  this->size = (arg_person["size"]).asInt();
  this->weight = (arg_person["weight"]).asInt();
  this->age = (arg_person["age"]).asInt();
  this->hasWindshield = (arg_person["hasWindshield"]).asBool();
  this->hasHelmet = (arg_person["hasHelmet"]).asBool();

  return true;
}




