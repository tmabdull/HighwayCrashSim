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

using namespace jsonrpc;
using namespace std;

// my location

int main()
{
  Person MotorcycleDriver3("Lane 3 Motorcycle Driver", 80, 150, 40, false, true);
  Motorcycle motor2("Harley Davidson", "motor 2", 2, 1, 70); //

  // HttpClient httpclient("http://127.0.0.1:7375");
  // hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;
  Json::Value gps;
  gps["location"] = "lane3";

  Json::Value ev3 = motor2.dump2JSON();
  myJSON2File((char *)"Lane3File.json", &ev3);
  // cout << MotorcycleDriver2.dump2JSON().toStyledString() << endl; //
  cout << motor2.dump2JSON().toStyledString() << endl; //

  Json::Value pev3 = MotorcycleDriver3.dump2JSON();
  myJSON2File((char *)"Lane3RiderFile.json", &pev3);
  cout << MotorcycleDriver3.dump2JSON().toStyledString() << endl;

  HttpServer httpserver(7376);
  Myhw5Server s(httpserver, JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  s.StartListening();
  std::cout << "Hit enter to stop the server" << endl;
  getchar();

  s.StopListening();

  return 0;
}
