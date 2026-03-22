#include <iostream>
#include "SmartHomeManager.h"
#include "Light.h"
#include "Thermostat.h"
#include "DoorLock.h"

using namespace std;

int main()
{
    SmartHomeManager manager;

    // Create devices
    // Note: Allocates memory dynamically
    manager.addLightingDevice(new Light("Living Room Light", 1));
    manager.addEnvironmentDevice(new Thermostat("Main Thermostat", 2));
    manager.addLightingDevice(new DoorLock("Front Door", 3));

    int choice;

    while (true)
    {
        cout << "\n---/// Smart Home Control ///---\n";
        cout << "1. Show All Devices\n";
        cout << "2. Turn ON Light\n";
        cout << "3. Set Temperature\n";
        cout << "4. Lock Door\n";
        cout << "5. Unlock Door\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        try
        {
            if (choice == 1)
            {
                manager.displayAll();
            }
            else if (choice == 2)
            {
                auto device = manager.findDevice(1);
                // Note: safely converts base pointer to derived pointer.
                auto light = dynamic_cast<Light*>(device);
                if (light) light->turnOn();
                cout << "Lights have been turned on.\n"; 
            }
            else if (choice == 3)
            {
                float temp;
                cout << "Enter temperature: ";
                cin >> temp;

                auto device = manager.findDevice(2);
                auto t = dynamic_cast<Thermostat*>(device);
                if (t) t->setTemperature(temp);
            }
            else if (choice == 4)
            {
                auto device = manager.findDevice(3);
                auto door = dynamic_cast<DoorLock*>(device);
                if (door) door->lock();
                cout << "Door has been locked.\n";
            }
            else if (choice == 5)
            {
                auto device = manager.findDevice(3);
                auto door = dynamic_cast<DoorLock*>(device);
                if (door) door->unlock();
            }
            else if (choice == 6)
            {
                break;
            }
        }
        catch (exception& e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}