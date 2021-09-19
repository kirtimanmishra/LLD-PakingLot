#include <bits/stdc++.h>
#include "Parking/ParkingLot.cpp"
#include "vehicles/Vehicle.cpp"
#include "Parking/ParkingSpotType.cpp"
#include "Parking/ParkingSpot.cpp"
#include "Parking/ParkingTicket.cpp"
#include "Parking/EntryGate.cpp"
#include "Parking/ExitGate.cpp"
#include "Parking/LargeSpot.cpp"
#include "Parking/MediumSpot.cpp"
#include "Parking/SmallSpot.cpp"

#include "vehicles/Truck.cpp"
#include "vehicles/Bus.cpp"
#include "vehicles/Car.cpp"
#include "vehicles/Bike.cpp"
#include "User/Admin.cpp"

#pragma once

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
    Admin admin("admin@gmail.com", "7002109950");
    EntryGate e1("e1Id1");
    EntryGate e2("e2Id2");

    ExitGate ex1("ex1Id1");
    ExitGate ex2("ex2Id2");

    EntryGate addede1 = admin.addEntryGate(e1);
    EntryGate addede2 = admin.addEntryGate(e2);

    addede1.details();
    addede2.details();

    ExitGate addedex1 = admin.addExitGate(ex1);
    ExitGate addedex2 = admin.addExitGate(ex2);

    addedex1.details();
    addedex2.details();

    LargeSpot lS1("lS1Id1");
    LargeSpot lS2("lS2Id2");

    MediumSpot mS1("mS1Id1");
    MediumSpot mS2("mS2Id2");

    SmallSpot sS1("sS1Id1");
    SmallSpot sS2("sSId2");

    LargeSpot addedlS1 = admin.addLargeSpot(lS1);
    LargeSpot addedlS2 = admin.addLargeSpot(lS2);
    addedlS1.showSpotDetails();
    addedlS2.showSpotDetails();

    MediumSpot addedmS1 = admin.addMediumSpot(mS1);
    MediumSpot addedmS2 = admin.addMediumSpot(mS2);
    addedmS1.showSpotDetails();
    addedmS2.showSpotDetails();

    SmallSpot addedsS1 = admin.addSmallSpot(sS1);
    SmallSpot addedsS2 = admin.addSmallSpot(sS2);
    addedsS1.showSpotDetails();
    addedsS2.showSpotDetails();
}
