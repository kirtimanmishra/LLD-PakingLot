#include <bits/stdc++.h>
#include "ParkingSpot.cpp"
using namespace std;
#pragma once

class MediumSpot : public ParkingSpot
{
  string parkingSpotId;

public:
  MediumSpot(string parkingSpotId) : ParkingSpot(parkingSpotId, MEDIUM)
  {
  }
};