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

    MediumSpot mS1("mS1Id1");

    SmallSpot sS1("sS1Id1");

    LargeSpot addedlS1 = admin.addLargeSpot(lS1);
    addedlS1.showSpotDetails();

    MediumSpot addedmS1 = admin.addMediumSpot(mS1);
    addedmS1.showSpotDetails();

    SmallSpot addedsS1 = admin.addSmallSpot(sS1);
    addedsS1.showSpotDetails();

    int T = 3;
    for (int i = 0; i < T; i++)
    {
        if (i == 0)
        {
            cout << " ---- >>>> BUS ----- " << endl;
            cout << endl;
            Bus bus("b1Id1");
            cout << "Available spot for Bus " << admin.checkAvailableSpot(bus) << endl;
            cout << "Availablility of Bus Entry Gate " << admin.checkEntryGateFree() << endl;
            // If spot not available, go back
            if (!admin.checkAvailableSpot(bus))
            {
                continue;
            }
            ParkingSpot parkingSpot = admin.allocateSpot(bus);
            parkingSpot.showSpotDetails();
            EntryGate entryGate = admin.AssignEntryGate();
            ParkingTicket parkingTicket = entryGate.assignTicket(bus, parkingSpot);
            cout << "Parking ticket details " << parkingTicket.getParkingTicketId() << endl;
            entryGate.setFreeGate();
            entryGate.details();

            cout << "Availablility of Bus Exit Gate " << admin.checkExitGateFree() << endl;

            ExitGate exitGate = admin.AssignExitGate();

            parkingTicket = exitGate.assignFreeTicket(parkingTicket);
            float payment = exitGate.generatePayment(parkingTicket, bus);
            exitGate.setFreeGate();
            exitGate.details();

            cout << "Payment to be made " << payment << endl;
        }
        if (i == 1)
        {
            cout << " ---- >>>> CAR ----- " << endl;
            cout << endl;

            Car car("c1Id1");
            cout << "Available spot for Car " << admin.checkAvailableSpot(car) << endl;
            cout << "Availablility of Car Entry Gate " << admin.checkEntryGateFree() << endl;
            // If spot not available, go back
            if (!admin.checkAvailableSpot(car))
            {
                continue;
            }
            ParkingSpot parkingSpot = admin.allocateSpot(car);
            parkingSpot.showSpotDetails();
            EntryGate entryGate = admin.AssignEntryGate();
            ParkingTicket parkingTicket = entryGate.assignTicket(car, parkingSpot);
            cout << "Parking ticket details " << parkingTicket.getParkingTicketId() << endl;
            entryGate.setFreeGate();
            entryGate.details();

            cout << "Availablility of CAR Exit Gate " << admin.checkExitGateFree() << endl;

            ExitGate exitGate = admin.AssignExitGate();

            parkingTicket = exitGate.assignFreeTicket(parkingTicket);
            float payment = exitGate.generatePayment(parkingTicket, car);
            exitGate.setFreeGate();
            exitGate.details();

            cout << "Payment to be made " << payment << endl;
        }
        if (i == 2)
        {
            cout << " ---- >>>> TRUCK ----- " << endl;
            cout << endl;

            Truck truck("t1Id1"); // Space Not Available, Entry gate Not Avaialble
            cout << "Available spot for Truck " << admin.checkAvailableSpot(truck) << endl;
            cout << "Availablility of Car Entry Gate " << admin.checkEntryGateFree() << endl;
            // If spot not available, go back
            if (!admin.checkAvailableSpot(truck))
            {
                continue;
            }
            ParkingSpot parkingSpot = admin.allocateSpot(truck);
            parkingSpot.showSpotDetails();
            EntryGate entryGate = admin.AssignEntryGate();
            ParkingTicket parkingTicket = entryGate.assignTicket(truck, parkingSpot);
            cout << "Parking ticket details " << parkingTicket.getParkingTicketId() << endl;
            entryGate.setFreeGate();
            entryGate.details();

            cout << "Availablility of CAR Exit Gate " << admin.checkExitGateFree() << endl;

            ExitGate exitGate = admin.AssignExitGate();

            parkingTicket = exitGate.assignFreeTicket(parkingTicket);
            float payment = exitGate.generatePayment(parkingTicket, truck);
            exitGate.setFreeGate();
            exitGate.details();

            cout << "Payment to be made " << payment << endl;
        }
    }

    // Bike bike("bk1Id1");  // Space Available, Entry gate Not Avaialble
    // cout << "Available spot for car " << admin.checkAvailableSpot(car) << endl;
    // cout << "Available spot for truck " << admin.checkAvailableSpot(truck) << endl;
    // cout << "Available spot for bike " << admin.checkAvailableSpot(bike) << endl;
}
