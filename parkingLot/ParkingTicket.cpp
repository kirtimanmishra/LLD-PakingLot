#include <bits/stdc++.h>
#include <ctime>
#include "ParkingSpotType.cpp"
#include "ParkingTicketType.cpp"
using namespace std;
#pragma once

class ParkingTicket
{
  string parkingTicketId;
  time_t entryTime;
  time_t exitTime;
  string licenceNumber;
  ParkingSpotType parkingSpotType;
  string parkingSpotId;
  ParkingTicketType status;

  ParkingTicket(string parkingTicketId)
  {
    this->parkingTicketId = parkingTicketId;
    this->status = INACTIVE;
  }
};
