// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>

// for JsonRPCCPP
#include <iostream>
// #include "hw5server.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
// #include "hw5client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdio.h>

// ecs36b
// #include "IOT_Thing.h"
#include "Motorcycle.h"
#include "Car.h"
// #include "Thing.h"
#include <time.h>

using namespace jsonrpc;
using namespace std;

// std::map (key, value pairs)

// my location

class Myhw5Server : public hw5Server
{
public:
  Myhw5Server(AbstractServerConnector &connector, serverVersion_t type);
  virtual Json::Value move(const std::string &action,
                           const std::string &class_id,
                           const Json::Value &json_object,
                           const Json::Value &location,
                           const std::string &object_id);
  virtual Json::Value done();
  std::map<std::string, Car *> Car_Map;
  std::map<std::string, Motorcycle *> Motorcycle_Map;
  bool is_done = false;
};

Myhw5Server::Myhw5Server(AbstractServerConnector &connector, serverVersion_t type)
    : hw5Server(connector, type)
{
  std::cout << "Myhw5Server Object created" << std::endl;
}

// member functions

Json::Value Myhw5Server::move
(const std::string &action, const std::string &class_id,
const Json::Value &json_object, const Json::Value &location,
const std::string &object_id)
{
  // int error_code = 0;
  Json::Value result;

  if (class_id == "Car") {
    //For Car:
    cout << "\nMoving Car Object:\n"; //Debug Statement TA
    Car * lv_Car_ptr;

    if (Car_Map.find(object_id) != Car_Map.end())
    {
      lv_Car_ptr = Car_Map[object_id];
    }
    else
    {
      lv_Car_ptr = new Car {};
      Car_Map[object_id] = lv_Car_ptr;
    }
    lv_Car_ptr -> JSON2Object(json_object);
        //End Car
  }
  else if (class_id == "Motorcycle") {
    //For Motorcycle
    cout << "\nMoving Motorcycle Object:\n"; //Debug Statement TA
    Motorcycle * lv_Motorcycle_ptr;

    if (Motorcycle_Map.find(object_id) != Motorcycle_Map.end())
    {
      lv_Motorcycle_ptr = Motorcycle_Map[object_id];
    }
    else
    {
      lv_Motorcycle_ptr = new Motorcycle {};
      Motorcycle_Map[object_id] = lv_Motorcycle_ptr;
    }
    lv_Motorcycle_ptr -> JSON2Object(json_object);

    //End Motorcycle
  }

  else {
    //cout << "\n\nMOVE FUNCTION FAILED\n\n"; //Debug Statement TA
  }

  result = json_object;

  std::cout << "" << result.toStyledString() << std::endl;
  return result;
}

Json::Value Myhw5Server::done()
{
  // int error_code = 0;
  Json::Value result;
  result[""] = "all data sent";
  std::cout << result.toStyledString() << std::endl;
  std::cout << "Done: All data sent!" << std::endl;
  this->is_done = true;
  return result;
}