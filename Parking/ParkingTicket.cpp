#include <bits/stdc++.h>
#include <ctime>
#include "ParkingSpotType.cpp"
#include "ParkingTicketType.cpp"
using namespace std;
#pragma once

class ParkingTicket
{
  string parkingTicketId;
  string entryTime;
  string exitTime;
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
  void setEntryTime(string entryTime)
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
  void setExitTime(string exitTime)
  {
    this->exitTime = exitTime;
  }
  string getEntryTime()
  {
    return entryTime;
  }
  string getEXitTime()
  {
    return exitTime;
  }
};