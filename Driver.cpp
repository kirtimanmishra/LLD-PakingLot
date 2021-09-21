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

Admin admin("admin@gmail.com", "7002109950");
EntryGate e1("e1Id1");
EntryGate e2("e2Id2");

ExitGate ex1("ex1Id1");
ExitGate ex2("ex2Id2");
EntryGate addede1 = admin.addEntryGate(e1);
EntryGate addede2 = admin.addEntryGate(e2);

ExitGate addedex1 = admin.addExitGate(ex1);
ExitGate addedex2 = admin.addExitGate(ex2);

LargeSpot lS1("lS1Id1");

MediumSpot mS1("mS1Id1");

SmallSpot sS1("sS1Id1");

LargeSpot addedlS1 = admin.addLargeSpot(lS1);

MediumSpot addedmS1 = admin.addMediumSpot(mS1);

SmallSpot addedsS1 = admin.addSmallSpot(sS1);

ParkingSpot Automate(Vehicle vehicle)
{
    // Checks for any incoming vehicle, no vehicle is exiting
    cout << "Available spot for  " << admin.checkAvailableSpot(vehicle) << endl;
    cout << "Availablility of  Entry Gate " << admin.checkEntryGateFree() << endl;
    // If spot not available, go back
    ParkingSpot parkingSpotDummy;
    if (!admin.checkAvailableSpot(vehicle))
    {
        return parkingSpotDummy;
    }
    ParkingSpot parkingSpot = admin.allocateSpot(vehicle);
    parkingSpot.showSpotDetails();
    EntryGate entryGate = admin.AssignEntryGate();
    ParkingTicket parkingTicket = entryGate.assignTicket(vehicle, parkingSpot);
    cout << "Parking ticket details " << parkingTicket.getParkingTicketId() << endl;
    entryGate.setFreeGate();
    entryGate.details();

    cout << "Availablility of  Exit Gate " << admin.checkExitGateFree() << endl;

    ExitGate exitGate = admin.AssignExitGate();

    parkingTicket = exitGate.assignFreeTicket(parkingTicket);
    float payment = exitGate.generatePayment(parkingTicket, vehicle);
    exitGate.setFreeGate();
    exitGate.details();

    cout << "Payment to be made " << payment << endl;
    return parkingSpot;
}

void Automate(Vehicle vehicle, ParkingSpot parkingSpot)
{
    // Checks for any botn incoming vehicle, and vehicle is exiting. That spot is getting free
    parkingSpot.showSpotDetails();
    cout << "given parking spot is getting free " << endl;
    cout << "Available spot for vehicle " << admin.checkAvailableSpot(vehicle) << endl;
    cout << "Availablility of  Entry Gate " << admin.checkEntryGateFree() << endl;
    admin.deAllocateSpot(parkingSpot);

    // If spot not available, go back
    if (!admin.checkAvailableSpot(vehicle))
    {
        return;
    }
    ParkingSpot parkingSpot1 = admin.allocateSpot(vehicle);
    parkingSpot1.showSpotDetails();
    EntryGate entryGate = admin.AssignEntryGate();
    ParkingTicket parkingTicket = entryGate.assignTicket(vehicle, parkingSpot1);
    cout << "Parking ticket details " << parkingTicket.getParkingTicketId() << endl;
    entryGate.setFreeGate();
    entryGate.details();

    cout << "Availablility of  Exit Gate " << admin.checkExitGateFree() << endl;

    ExitGate exitGate = admin.AssignExitGate();

    parkingTicket = exitGate.assignFreeTicket(parkingTicket);
    float payment = exitGate.generatePayment(parkingTicket, vehicle);
    exitGate.setFreeGate();
    exitGate.details();

    cout << "Payment to be made " << payment << endl;
}

int main()
{
    addede1.details();
    addede2.details();

    addedex1.details();
    addedex2.details();

    addedlS1.showSpotDetails();

    addedmS1.showSpotDetails();

    addedsS1.showSpotDetails();
    cout << endl;

    ParkingSpot parkingSpot1, parkingSpot2;

    int T = 4;
    for (int i = 0; i < T; i++)
    {
        if (i == 0)
        {
            cout << " ---- >>>> BUS 1 ----- " << endl;
            cout << endl;
            Bus bus("b1Id1");
            parkingSpot1 = Automate(bus);
        }
        if (i == 1)
        {
            cout << " ---- >>>> CAR 2 ----- " << endl;
            cout << endl;
            Car car("c1Id1");
            Automate(car);
        }
        if (i == 2)
        {
            cout << " ---- >>>> TRUCK 3 ----- " << endl;
            cout << endl;
            Truck truck("t1Id1"); // Space Not Available, Entry gate Not Avaialble
            Automate(truck);
        }
        if (i == 3)
        {
            cout << " ---- >>>> TRUCK 4 ----- " << endl;
            cout << endl;
            cout << " -- >>>> BUS wants to go out, Space Available for truck " << endl;
            Truck truck("t1Id1"); // Space Not Available, Entry gate Not Avaialble
            Automate(truck, parkingSpot1);
        }
    }
    return 0;
}
