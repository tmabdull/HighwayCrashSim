#include "Auto.h"

Auto::Auto(int arg_numWheels, int arg_totalRiders, int arg_autoWeight, int arg_autoSize, int arg_speed, string arg_pColor, string arg_sColor, bool arg_autoDanger)
{
  this->numWheels = arg_numWheels;
  this->totalRiders = arg_totalRiders;
  this->autoWeight = arg_autoWeight;
  this->autoSize = arg_autoSize;
  this->speed = arg_speed;
  this->primaryColor = arg_pColor;
  this->secondaryColor = arg_sColor;
  this->autoIsInDanger = arg_autoDanger;
}

Auto::Auto()
{
  this->numWheels = 0;
  this->totalRiders = 0;
  this->autoWeight = 0;
  this->autoSize = 0;
  this->speed = 0;
  this->primaryColor = "";
  this->secondaryColor = "";
  this->autoIsInDanger = false;
}