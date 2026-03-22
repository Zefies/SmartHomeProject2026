#include <iostream>
#include "SmartHomeManager.h"
#include "Exceptions.h"

using namespace std;

// Add functions
void SmartHomeManager::addLightingDevice(SmartDevice* device)
{
    lighting.push_back(device);
}

void SmartHomeManager::addSecurityDevice(SmartDevice* device)
{
    security.push_back(device);
}

void SmartHomeManager::addEnvironmentDevice(SmartDevice* device)
{
    environment.push_back(device);
}

// Display everything
// Note: d is a pointer to a SmartDevice object. **RUNTIME POLYMORPHISM**
void SmartHomeManager::displayAll() const
{
    cout << "--- Lighting System ---" << endl;
    for (auto d : lighting)
        d->display();

    cout << "--- Security System ---" << endl;
    for (auto d : security)
        d->display();

    cout << "--- Environment System ---" << endl;
    for (auto d : environment)
        d->display();
}

// Find device by ID
SmartDevice* SmartHomeManager::findDevice(int id) const
{
    for (auto d : lighting)
        if (d->getID() == id)
            return d;

    for (auto d : security)
        if (d->getID() == id)
            return d;

    for (auto d : environment)
        if (d->getID() == id)
            return d;

    throw runtime_error("Device not found");
}

// Destructor
SmartHomeManager::~SmartHomeManager()
{
    for (auto d : lighting)
        delete d;

    for (auto d : security)
        delete d;

    for (auto d : environment)
        delete d;
}