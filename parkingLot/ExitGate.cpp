#include <bits/stdc++.h>
#include <ctime>
#include "ParkingSpotType.cpp"
#include "ParkingTicketType.cpp"
#include "ParkingTicket.cpp"
#include "../vehicles/Vehicle.cpp"
#include "ParkingSpot.cpp"

using namespace std;
#pragma once

class ExitGate
{
  string entryGateId;
  bool isFreeGate;

public:
  ExitGate() {}
  ExitGate(string entryGateId)
  {
    this->entryGateId = entryGateId;
    this->isFreeGate = true;
  }
  ParkingTicket assignFreeTicket(ParkingTicket parkingTicket)
  {
    time_t now = time(0);
    char *dt = ctime(&now);
    parkingTicket.setExitTime(dt);
    parkingTicket.setDeactiveStatus();
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
};
