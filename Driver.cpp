#include <bits/stdc++.h>
#include "./vehicles/Car.cpp"
#include "./vehicles/Bike.cpp"
#include "./vehicles/Bus.cpp"
#include "./parkingLot/SmallSpot.cpp"
#include "./parkingLot/LargeSpot.cpp"

using namespace std;

class Driver
{

public:
    Driver()
    {
    }
};

int main()
{
    Car WagonR("AS158055");
    Bike Apache("AS157577");
    Bus Volvo("AS157578");

    SmallSpot small("1234");
    LargeSpot large("1236");

    small.showSpotDetails();
    large.showSpotDetails();
}
