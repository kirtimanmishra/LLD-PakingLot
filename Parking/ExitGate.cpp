#include <bits/stdc++.h>
#include <ctime>
#include "ParkingSpotType.cpp"
#include "ParkingTicketType.cpp"
#include "ParkingTicket.cpp"
#include "ParkingSpot.cpp"
#include "PaymentRate.cpp"

using namespace std;
#pragma once

class ExitGate
{
  string exitGateId;
  bool isFreeGate;

public:
  ExitGate() {}
  ExitGate(string exitGateId)
  {
    this->exitGateId = exitGateId;
    this->isFreeGate = true;
  }
  ParkingTicket assignFreeTicket(ParkingTicket parkingTicket)
  {
    time_t now = time(0);
    // char *dt = ctime(&now);
    parkingTicket.setExitTime(now);
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
  float generatePayment(ParkingTicket parkingTicket, Vehicle vehicle)
  {
    isFreeGate = false;
    PaymentRate paymentRate;
    time_t entryTime = parkingTicket.getEntryTime();
    time_t exitTime = parkingTicket.getEXitTime();
    float rate = paymentRate.getVehicleRate(vehicle);
    time_t diff = exitTime - entryTime;
    if (diff == 0)
      diff = 1;
    float sum = diff * rate * 100;
    return sum;
  }
  void details()
  {
    cout << "Exit Gate Details --- entryGateId" << exitGateId << " isFreeGate " << isFreeGate << endl;
  }
};
