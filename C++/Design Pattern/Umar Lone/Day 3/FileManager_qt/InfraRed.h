#ifndef INFRARED_H
#define INFRARED_H


#include "TransferPolicy.h"

class InfraRed : public TransferPolicy
{
public:
    InfraRed();
    void transfer(const std::string& filename);
};

#endif // INFRARED_H
