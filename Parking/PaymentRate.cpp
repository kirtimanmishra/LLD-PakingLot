#include <bits/stdc++.h>
#include <ctime>
#include "ParkingSpotType.cpp"
#include "ParkingTicketType.cpp"
#include "ParkingTicket.cpp"
#include "../vehicles/Vehicle.cpp"
#include "ParkingSpot.cpp"
#include "../vehicles/Car.cpp"
#include "../vehicles/Bike.cpp"
using namespace std;
#pragma once

class PaymentRate
{
  unordered_map<VehicleType, float> Rate;

public:
  PaymentRate()
  {
    Rate[TRUCK] = 1.5;
    Rate[BUS] = 1.25;
    Rate[CAR] = 1.0;
    Rate[BIKE] = 0.5;
  }
  float getVehicleRate(Vehicle vehicle)
  {
    return Rate[vehicle.getVehicleType()];
  }
};
