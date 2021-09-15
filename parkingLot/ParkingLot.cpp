#include <bits/stdc++.h>
#include "../vehicles/Vehicle.cpp"
#include "ParkingSpotType.cpp"
#include "ParkingSpot.cpp"
#include "ParkingTicket.cpp"
#include "EntryGate.cpp"
#include "ExitGate.cpp"

#pragma once
using namespace std;

class ParkingLot
{
  string parkingId;
  unordered_map<ParkingSpotType, vector<ParkingSpot>> parkingSpace;
  unordered_map<string, ParkingSpot> usedParkingSpace;
  vector<EntryGate> entryGates;
  vector<ExitGate> exitGates;

  EntryGate entryGate;
  ExitGate exitGate;

  VehicleType vehicleType;
  ParkingSpot parkingSpot;

public:
  ParkingLot()
  {
  }
  ParkingLot(string parkingId)
  {
    this->parkingId = parkingId;
    this->parkingSpace[LARGE] = {};
    this->parkingSpace[MEDIUM] = {};
    this->parkingSpace[SMALL] = {};
    this->entryGates = {};
    this->exitGates = {};
  }
  VehicleType getVehicleType(Vehicle vehicle)
  {
    this->vehicleType = vehicle.getVehicleType();
    return vehicleType;
  }
  bool checkEntryGateFree()
  {
    for (int i = 0; i < entryGates.size(); i++)
    {
      EntryGate entryGate = entryGates[i];
      if (entryGate.checkGateAvailability())
      {
        this->entryGate = entryGate;
        return true;
      }
      return false;
    }
  }
  EntryGate AssignEntryGate()
  {
    return entryGate;
  }

  bool checkExitGateFree()
  {
    for (int i = 0; i < exitGates.size(); i++)
    {
      ExitGate exitGate = exitGates[i];
      if (exitGate.checkGateAvailability())
      {
        this->exitGate = exitGate;
        return true;
      }
      return false;
    }
  }
  ExitGate AssignExitGate()
  {
    return exitGate;
  }

  bool checkAvailableSpot(Vehicle vehicle)
  {
    if (vehicleType == TRUCK || vehicleType == BUS)
    {
      return parkingSpace[LARGE].size() > 0;
    }
    if (vehicleType == CAR)
    {
      return parkingSpace[MEDIUM].size() > 0;
    }
    return parkingSpace[SMALL].size() > 0;
  }
  ParkingSpot allocateSpot(Vehicle vehicle)
  {
    if (vehicleType == TRUCK || vehicleType == BUS)
    {
      auto it = parkingSpace[LARGE].begin();
      this->parkingSpot = *it;
      parkingSpace[LARGE].erase(it);
      usedParkingSpace[parkingSpot.getParkingSpotId()] = parkingSpot;
    }
    else if (vehicleType == CAR)
    {
      auto it = parkingSpace[MEDIUM].begin();
      this->parkingSpot = *it;
      parkingSpace[MEDIUM].erase(it);
      usedParkingSpace[parkingSpot.getParkingSpotId()] = parkingSpot;
    }
    auto it = parkingSpace[SMALL].begin();
    this->parkingSpot = *it;
    parkingSpace[SMALL].erase(it);
    usedParkingSpace[parkingSpot.getParkingSpotId()] = parkingSpot;
    return parkingSpot;
  }
};
