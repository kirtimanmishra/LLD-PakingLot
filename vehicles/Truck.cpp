#include <bits/stdc++.h>
#include "../vehicles/Vehicle.cpp"
#pragma once

class Truck : public Vehicle
{
  string licenceNumber;

public:
  Truck(string licenceNumber) : Vehicle(licenceNumber, BUS)
  {
  }
};
