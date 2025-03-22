#ifndef TRANSFERPOLICY_H
#define TRANSFERPOLICY_H
#include <string>


class TransferPolicy
{
public:
    TransferPolicy() = default;
    virtual void transfer(const std::string& filename) = 0;
    ~TransferPolicy() = default;
};

#endif // TRANSFERPOLICY_H
