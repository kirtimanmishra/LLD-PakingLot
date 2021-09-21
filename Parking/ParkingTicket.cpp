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

public:
  ParkingTicket(string parkingTicketId)
  {
    this->parkingTicketId = parkingTicketId;
    this->status = INACTIVE;
  }
  void setActiveStatus()
  {
    this->status = ACTIVE;
  }
  void setDeactiveStatus()
  {
    this->status = INACTIVE;
  }
  void setEntryTime(time_t entryTime)
  {
    this->entryTime = entryTime;
  }
  void setLicenceNumber(string licenceNumber)
  {
    this->licenceNumber = licenceNumber;
  }
  void setParkingSpotId(string parkingSpotId)
  {
    this->parkingSpotId = parkingSpotId;
  }
  void setParkingType(ParkingSpotType parkingSpotType)
  {
    this->parkingSpotType = parkingSpotType;
  }
  void setExitTime(time_t exitTime)
  {
    this->exitTime = exitTime;
  }
  time_t getEntryTime()
  {
    return entryTime;
  }
  time_t getEXitTime()
  {
    return exitTime;
  }
  string getParkingTicketId()
  {
    return parkingTicketId;
  }
};