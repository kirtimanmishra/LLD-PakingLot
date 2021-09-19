#include <bits/stdc++.h>
using namespace std;
#include "ParkingSpotType.cpp"
#include "../vehicles/Vehicle.cpp"
#pragma once

class ParkingSpot
{
  string parkingSpotId;
  ParkingSpotType parkingSpotType;
  bool isFree = true;
  Vehicle assignedVehicle;

public:
  ParkingSpot()
  {
  }
  ParkingSpot(string parkingSpotId, ParkingSpotType parkingSpotType)
  {
    this->parkingSpotId = parkingSpotId;
    this->parkingSpotType = parkingSpotType;
  }

  bool canPark()
  {
    return isFree == true;
  }
  Vehicle allocateSpot(Vehicle vehicle)
  {
    this->assignedVehicle = vehicle;
    this->isFree = false;
    return vehicle;
  }
  Vehicle vacateSpot(Vehicle vehicle)
  {
    Vehicle emptyVehicle;
    this->assignedVehicle = emptyVehicle;
    this->isFree = true;
    return vehicle;
  }
  string getParkingSpotId()
  {
    return parkingSpotId;
  }
  ParkingSpotType getParkingSpotType()
  {
    return parkingSpotType;
  }
  void showSpotDetails()
  {
    cout << "Spot Details --- parkingSpotId " << parkingSpotId << " parkingSpotType " << parkingSpotType << endl;
  }
};
