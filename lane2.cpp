
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
// #include "lane1.cpp"

using namespace jsonrpc;
using namespace std;

// my location

int main()
{
  Car car("Honda", "Civic", 4, 1, 80);
  // Person CarDriver("Car Driver", 85, 180, 35, true, false);

  // Json::Value myv;
  // Json::Value gps;
  // gps["location"] = "lane2";

  // HttpServer httpserver(7375);
  // Myhw5Server s(httpserver, JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)

  Json::Value Lane1MotorJSONcpy;
  myFile2JSON((char *)"Lane1MotorFile.json", &Lane1MotorJSONcpy);
  Motorcycle Lane1MotorObj;
  Lane1MotorObj.JSON2Object(Lane1MotorJSONcpy);
  cout << Lane1MotorObj.Make << Lane1MotorObj.speed << endl;

  Json::Value Lane1RiderJSONcpy;
  myFile2JSON((char *)"Lane1RiderFile.json", &Lane1RiderJSONcpy);
  Person Lane1RiderObj;
  Lane1RiderObj.JSON2Object(Lane1RiderJSONcpy);
  cout << Lane1RiderObj.age << Lane1RiderObj.hasWindshield << Lane1RiderObj.hasHelmet << endl;

  Json::Value Lane3MotorJSONcpy;
  myFile2JSON((char *)"Lane3MotorFile.json", &Lane3MotorJSONcpy);
  Motorcycle Lane3MotorObj;
  Lane3MotorObj.JSON2Object(Lane3MotorJSONcpy);
  cout << Lane3MotorObj.Make << Lane3MotorObj.speed << endl;

  Json::Value Lane3RiderJSONcpy;
  myFile2JSON((char *)"Lane3RiderFile.json", &Lane3RiderJSONcpy);
  Person Lane3RiderObj;
  Lane3RiderObj.JSON2Object(Lane3RiderJSONcpy);
  cout << Lane3RiderObj.age << Lane3RiderObj.hasWindshield << Lane3RiderObj.hasHelmet << endl;

  int lane1SurvivalChance = 0;
  int lane3SurvivalChance = 0;

  if (Lane1MotorObj.speed < Lane3MotorObj.speed)
  {
    lane1SurvivalChance++;
  }
  else if (Lane1MotorObj.speed > Lane3MotorObj.speed)
  {
    lane3SurvivalChance++;
  }

  if (Lane1MotorObj.totalRiders < Lane3MotorObj.totalRiders)
  {
    lane1SurvivalChance++;
  }
  else if (Lane1MotorObj.totalRiders > Lane3MotorObj.totalRiders)
  {
    lane3SurvivalChance++;
  }

  if (Lane1RiderObj.age < Lane3RiderObj.age)
  {
    lane1SurvivalChance++;
  }
  else if (Lane3RiderObj.age < Lane1RiderObj.age)
  {
    lane3SurvivalChance++;
  }

  if (Lane1RiderObj.hasWindshield && !Lane3RiderObj.hasWindshield)
  {
    lane1SurvivalChance++;
  }
  else if (Lane3RiderObj.hasWindshield && !Lane1RiderObj.hasWindshield)
  {
    lane3SurvivalChance++;
  }

  if (Lane1RiderObj.hasHelmet && !Lane3RiderObj.hasHelmet)
  {
    lane1SurvivalChance++;
  }
  else if (Lane3RiderObj.hasHelmet && !Lane1RiderObj.hasHelmet)
  {
    lane3SurvivalChance++;
  }


  cout << "Lane 1 Survival Score: " << lane1SurvivalChance << endl;
  cout << "Lane 3 Survival Score: " << lane3SurvivalChance << endl;

  Json::Value myv;
  Json::Value gps;
  gps["location"] = "lane2";

  if (lane1SurvivalChance > lane3SurvivalChance)
  {
    HttpClient httpclient("http://127.0.0.1:7374");
    hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
    try
    {
      myv = myClient.move("move", "Car",
                          car.dump2JSON(),
                          gps,
                          "Lane1");
    }
    catch (JsonRpcException &e)
    {
      cerr << e.what() << endl;
    }
    std::cout << myv.toStyledString() << std::endl;
  }
  else
  {
    HttpClient httpclient("http://127.0.0.1:7376");
    hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
    try
    {
      myv = myClient.move("move", "Car",
                          car.dump2JSON(),
                          gps,
                          "Lane3");
    }
    catch (JsonRpcException &e)
    {
      cerr << e.what() << endl;
    }
    std::cout << myv.toStyledString() << std::endl;
  }

  HttpServer httpserver(7375);
  Myhw5Server s(httpserver, JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  s.StartListening();
  std::cout << "Hit enter to stop the server" << endl;
  getchar();
  s.StopListening();
  return 0;
}

//Car loop
// for (auto it = s.Car_Map.begin(); it != s.Car_Map.end(); it++) {
//   try {
//     myv = myClient.move("move", "Car",
//       s.Car_Map[it->first]->dump2JSON(),
//       gps,
//       it->first);
//   } catch (JsonRpcException &e) {
//     cerr << e.what() << endl;
//   }
//   std::cout << myv.toStyledString() << std::endl;

// }
