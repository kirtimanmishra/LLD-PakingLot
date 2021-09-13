#include <bits/stdc++.h>
using namespace std;
#include "../vehicles/Vehicle.cpp"

class ParkingLot
{
  string parkingId;
  unordered_map<VehicleType, vector<Vehicle>> parkingSpace;
  unordered_map<string, Vehicle> usedParkingSpace;

public:
  ParkingLot(string parkingId)
  {
    this->parkingId = parkingId;
    this->parkingSpace[CAR] = {};
    this->parkingSpace[BUS] = {};
    this->parkingSpace[TRUCK] = {};
    this->parkingSpace[BIKE] = {};
  }
};
