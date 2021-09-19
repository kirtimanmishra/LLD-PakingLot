#include <bits/stdc++.h>
#include "../vehicles/Vehicle.cpp"
#pragma once

class Bus : public Vehicle
{
  string licenceNumber;

public:
  Bus(string licenceNumber) : Vehicle(licenceNumber, BUS) {}
};
