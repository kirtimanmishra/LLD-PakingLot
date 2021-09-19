#include <bits/stdc++.h>
#include "../vehicles/Vehicle.cpp"
#pragma once

class Bike : public Vehicle
{
  string licenceNumber;
  VehicleType vehicleType;

public:
  Bike(string licenceNumber) : Vehicle(licenceNumber, BIKE) {}
};
