#include <bits/stdc++.h>
#include "Account.cpp"
#pragma once
using namespace std;

class Person : public Account
{
public:
  Person(string email, string phone) : Account(email, phone) {}
};