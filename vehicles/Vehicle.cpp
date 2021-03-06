#include <bits/stdc++.h>
#include "../vehicles/VehicleType.cpp"

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
  VehicleType getVehicleType()
  {
    return vehicleType;
  }
  string getLicenceNumber()
  {
    return licenceNumber;
  }
};
