#ifndef SMARTHOMEMANAGER_H
#define SMARTHOMEMANAGER_H

#include <vector>
#include "SmartDevice.h"

using namespace std;

class SmartHomeManager
{
private:
    vector<SmartDevice*> lighting;
    vector<SmartDevice*> security;
    vector<SmartDevice*> environment;

public:
    // Add devices to specific system
    void addLightingDevice(SmartDevice* device);
    void addSecurityDevice(SmartDevice* device);
    void addEnvironmentDevice(SmartDevice* device);

    // Display everything
    void displayAll() const;

    // Find device by ID
    SmartDevice* findDevice(int id) const;

    // Destructor to clean memory
    ~SmartHomeManager();
};

#endif