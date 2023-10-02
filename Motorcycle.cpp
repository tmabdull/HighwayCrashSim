#include "Motorcycle.h"

Motorcycle::Motorcycle(string arg_Make, string arg_Model, int arg_numWheels, int arg_totalRiders, int arg_speed)
{
  this->Make = arg_Make;
  this->Model = arg_Model;
  this->numWheels = arg_numWheels;
  this->totalRiders = arg_totalRiders;
  this->speed = arg_speed;
}

Motorcycle::Motorcycle()
{
  this->Make = "";
  this->Model = "";
  this->numWheels = 0;
  this->totalRiders = 0;
  this->speed = 0;
}

Json::Value Motorcycle::dump2JSON(void)
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
  //result["MotorcycleDanger"] = this->MotorcycleIsInDanger;
  //Auto::dump2JSON();

  return result;
}

bool Motorcycle::JSON2Object(Json::Value arg_Motorcycle)
{
  if (!arg_Motorcycle.isObject() || arg_Motorcycle.isNull())
  {
    return false;
  }
  this->Make = (arg_Motorcycle["make"]).asString();
  this->Model = (arg_Motorcycle["model"]).asString();
  this->numWheels = (arg_Motorcycle["numWheels"]).asInt();
  this->totalRiders = (arg_Motorcycle["totalRiders"]).asInt();
  this->speed = (arg_Motorcycle["speed"]).asInt();
  //this->MotorcycleIsInDanger = (arg_Motorcycle["MotorcycleDanger"]).asBool();

  return true;
}