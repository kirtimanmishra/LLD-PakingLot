#include <bits/stdc++.h>
#include "VehicleType.cpp"
#pragma once

using namespace std;

class Vehicle
{
  string licenceNumber;
  VehicleType vehicleType;

public:
  Vehicle() {}

  Vehicle(string licenceNumber, VehicleType vehicleType)
  {
    this->licenceNumber = licenceNumber;
    this->vehicleType = vehicleType;
  }
  void showVehicleDetails()
  {
    cout << "licenceNumber " << licenceNumber << " vehicleType " << vehicleType << endl;
  }
};