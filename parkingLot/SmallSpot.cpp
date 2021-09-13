#include <bits/stdc++.h>
#include "ParkingSpot.cpp"
using namespace std;
#pragma once

class SmallSpot : public ParkingSpot
{
  string parkingSpotId;

public:
  SmallSpot(string parkingSpotId) : ParkingSpot(parkingSpotId, SMALL)
  {
  }
};