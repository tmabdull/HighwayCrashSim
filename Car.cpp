#include "Car.h"

Car::Car(string arg_make, string arg_model, int arg_numWheels, int arg_totalRiders, int arg_speed)
{
  this->Make = arg_make;
  this->Model = arg_model;
  this->numWheels = arg_numWheels;
  this->totalRiders = arg_totalRiders;
  this->speed = arg_speed;
}

Car::Car()
{
  this->Make = "";
  this->Model = "";
  this->numWheels = 0;
  this->totalRiders = 0;
  this->speed = 0;
}

Json::Value Car::dump2JSON(void)
{
  Json::Value result{};

  if (this->Make != "")
  {
    result["make"] = this->Make;
  }
  if (this->Model != "")
  {
    result["model"] = this->Model;
  }
  if (this->numWheels != 0)
  {
    result["numWheels"] = this->numWheels;
  }
  if (this->totalRiders != 0)
  {
    result["totalRiders"] = this->totalRiders;
  }
  if (this->speed != 0)
  {
    result["speed"] = this->speed;
  }
  //result["CarDanger"] = this->CarIsInDanger;

  return result;
}

bool Car::JSON2Object(Json::Value arg_Car)
{
  if (!arg_Car.isObject() || arg_Car.isNull())
  {
    return false;
  }
  this->Make = (arg_Car["make"]).asString();
  this->Model = (arg_Car["model"]).asString();
  this->numWheels = (arg_Car["numWheels"]).asInt();
  this->totalRiders = (arg_Car["totalRiders"]).asInt();
  this->speed = (arg_Car["speed"]).asInt();
  //this->CarIsInDanger = (arg_Car["CarDanger"]).asBool();

  return true;
}