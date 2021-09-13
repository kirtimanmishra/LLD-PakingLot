#include <bits/stdc++.h>
#include "ParkingSpot.cpp"
using namespace std;
#pragma once

class LargeSpot : public ParkingSpot
{
  string parkingSpotId;

public:
  LargeSpot(string parkingSpotId) : ParkingSpot(parkingSpotId, LARGE)
  {
  }
};