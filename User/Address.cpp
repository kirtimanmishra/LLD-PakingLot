#include <bits/stdc++.h>
#pragma once
using namespace std;

class Address
{
  string address1;
  string address2;
  string pinCode;
  string city;
  string state;
  string country;

public:
  Address() {}
  Address(string address1, string address2, string pinCode, string city, string state, string country)
  {
    this->address1 = address1;
    this->address2 = address2;
    this->pinCode = pinCode;
    this->city = city;
    this->state = state;
    this->country = country;
  }
};
