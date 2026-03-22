#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>
using namespace std;

class SmartDevice
{
protected:
    string name;
    int id;

public:
    SmartDevice(string name, int id);

    virtual void display() const = 0;
    virtual void update() = 0;

    int getID() const;
    string getName() const;

    virtual ~SmartDevice() {}
};

#endif