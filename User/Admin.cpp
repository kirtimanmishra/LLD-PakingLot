#include <bits/stdc++.h>
#include "Account.cpp"
#include "../Parking/ParkingLot.cpp"
#pragma once
using namespace std;

class Admin : public Account, public ParkingLot
{
public:
  Admin(string email, string phone) : Account(email, phone) {}
};