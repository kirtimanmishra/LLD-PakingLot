#include <bits/stdc++.h>
using namespace std;

class Enum
{
public:
  enum
  {
    ONE,
    Two,
    Last
  };
};

class EnumDeriv : public Enum
{
  Enum enumType;

public:
  EnumDeriv() {}
  EnumDeriv(Enum enumType)
  {
    this->enumType = enumType;
  }
};

class One : public EnumDeriv
{
  One() : EnumDeriv(Enum::Two) {}
};

int main()
{
  std::cout << EnumDeriv::One << std::endl;
  // std::cout << EnumDeriv::Four << std::endl;
  return 0;
}