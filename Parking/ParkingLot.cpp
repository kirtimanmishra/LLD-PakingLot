#include <bits/stdc++.h>
#include "../vehicles/Vehicle.cpp"
#include "../vehicles/VehicleType.cpp"

#include "ParkingSpotType.cpp"
#include "ParkingSpot.cpp"
#include "ParkingTicket.cpp"
#include "EntryGate.cpp"
#include "ExitGate.cpp"

#include "LargeSpot.cpp"
#include "MediumSpot.cpp"
#include "SmallSpot.cpp"

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
    }
    return false;
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
    }
    return false;
  }
  ExitGate AssignExitGate()
  {
    return exitGate;
  }

  bool checkAvailableSpot(Vehicle vehicle)
  {
    VehicleType vehicleType = vehicle.getVehicleType();
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
    ParkingSpot parkingSpot;
    VehicleType vehicleType = vehicle.getVehicleType();

    if (vehicleType == TRUCK || vehicleType == BUS)
    {
      auto it = parkingSpace[LARGE].begin();
      parkingSpot = *it;
      parkingSpace[LARGE].erase(it);
      usedParkingSpace[parkingSpot.getParkingSpotId()] = parkingSpot;
      return parkingSpot;
    }
    else if (vehicleType == CAR)
    {
      auto it = parkingSpace[MEDIUM].begin();
      parkingSpot = *it;
      parkingSpace[MEDIUM].erase(it);
      usedParkingSpace[parkingSpot.getParkingSpotId()] = parkingSpot;
      return parkingSpot;
    }
    auto it = parkingSpace[SMALL].begin();
    parkingSpot = *it;
    parkingSpace[SMALL].erase(it);
    usedParkingSpace[parkingSpot.getParkingSpotId()] = parkingSpot;
    return parkingSpot;
  }
  ParkingSpot deAllocateSpot(ParkingSpot parkingSpot)
  {
    usedParkingSpace.erase(parkingSpot.getParkingSpotId());
    ParkingSpotType parkingSpotType = parkingSpot.getParkingSpotType();
    cout << "parking spot type " << parkingSpotType << endl;
    if (parkingSpotType == LARGE)
    {
      parkingSpace[LARGE].push_back(parkingSpot);
    }
    if (parkingSpotType == MEDIUM)
    {
      parkingSpace[MEDIUM].push_back(parkingSpot);
    }
    if (parkingSpotType == SMALL)
    {
      parkingSpace[SMALL].push_back(parkingSpot);
    }
    return parkingSpot;
  }

  EntryGate addEntryGate(EntryGate entryGate)
  {
    entryGates.push_back(entryGate);
    return entryGate;
  }
  ExitGate addExitGate(ExitGate exitGate)
  {
    exitGates.push_back(exitGate);
    return exitGate;
  }
  LargeSpot addLargeSpot(LargeSpot largeSpot)
  {
    parkingSpace[LARGE].push_back(largeSpot);
    return largeSpot;
  }
  MediumSpot addMediumSpot(MediumSpot mediumSpot)
  {
    parkingSpace[MEDIUM].push_back(mediumSpot);
    return mediumSpot;
  }
  SmallSpot addSmallSpot(SmallSpot smallSpot)
  {
    parkingSpace[SMALL].push_back(smallSpot);
    return smallSpot;
  }
};
