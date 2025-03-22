#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "TransferPolicy.h"

class BlueTooth : public TransferPolicy
{
public:
    BlueTooth();
    void transfer(const std::string& filename);
};

#endif // BLUETOOTH_H
