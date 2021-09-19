#include <bits/stdc++.h>
#include "Address.cpp"
#pragma once
using namespace std;

class Account
{
  string email;
  string phone;
  Address address;

public:
  Account(string email, string phone)
  {
    this->email = email;
    this->phone = phone;
  }
  Address setAddress(Address address)
  {
    this->address = address;
    return address;
  }
};