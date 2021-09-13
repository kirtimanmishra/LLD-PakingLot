#include <bits/stdc++.h>
#include "Vehicle.cpp"
#pragma once

class Car : public Vehicle
{
  string licenceNumber;

public:
  Car(string licenceNumber) : Vehicle(licenceNumber, CAR)
  {
  }
};
