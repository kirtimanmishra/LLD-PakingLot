#include <bits/stdc++.h>
#include <ctime>
#include "ParkingSpotType.cpp"
#include "ParkingTicketType.cpp"
#include "ParkingTicket.cpp"
#include "ParkingSpot.cpp"

using namespace std;
#pragma once

class EntryGate
{
  string entryGateId;
  bool isFreeGate;

public:
  EntryGate() {}
  EntryGate(string entryGateId)
  {
    this->entryGateId = entryGateId;
    this->isFreeGate = true;
  }
  ParkingTicket assignTicket(Vehicle vehicle, ParkingSpot parkingSpot)
  {
    string id = to_string(rand());
    ParkingTicket parkingTicket(id);
    parkingTicket.setActiveStatus();
    time_t now = time(0);
    // char *dt = ctime(&now);
    parkingTicket.setEntryTime(now);
    parkingTicket.setLicenceNumber(vehicle.getLicenceNumber());
    parkingTicket.setParkingSpotId(parkingSpot.getParkingSpotId());
    parkingTicket.setParkingType(parkingSpot.getParkingSpotType());
    isFreeGate = false;
    return parkingTicket;
  }
  bool checkGateAvailability()
  {
    return isFreeGate == true;
  }
  void setFreeGate()
  {
    isFreeGate = true;
  }
  void details()
  {
    cout << "Entry Gate Details --- entryGateId" << entryGateId << " isFreeGate " << isFreeGate << endl;
  }
};
