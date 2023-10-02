
// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>

// for JsonRPCCPP
#include <iostream>
#include "hw5server.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include "hw5client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdio.h>
#include "hw5server.cpp"
#include "ecs36b_Common.h"

// for Objects
#include "Motorcycle.h"
#include "Car.h"
#include "Auto.h"

using namespace jsonrpc;
using namespace std;

// my location

int main()
{
  Person MotorcycleDriver1("Lane 1 Motorcycle Driver", 90, 180, 30, true, true);
  Motorcycle motor1("Yamaha", "motor 1", 2, 2, 60);

  HttpClient httpclient("http://127.0.0.1:7375");
  hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;
  Json::Value gps;
  gps["location"] = "lane 1";

  Json::Value ev1 = motor1.dump2JSON();
  myJSON2File((char *)"Lane1MotorFile.json", &ev1);
  cout << motor1.dump2JSON().toStyledString() << endl;
  
  Json::Value pev1 = MotorcycleDriver1.dump2JSON();
  myJSON2File((char *)"Lane1RiderFile.json", &pev1);
  cout << MotorcycleDriver1.dump2JSON().toStyledString() << endl;

  // std::cout << Event1cpy.dump2JSON().toStyledString() << endl;
  // std::cout << Event1cpy.age << endl;

  HttpServer httpserver(7374);
  Myhw5Server s(httpserver, JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  s.StartListening();
  std::cout << "Hit enter to stop the server" << endl;
  getchar();

  s.StopListening();

  return 0;
}
