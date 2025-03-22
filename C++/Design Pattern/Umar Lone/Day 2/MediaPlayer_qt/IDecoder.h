#ifndef IDECODER_H
#define IDECODER_H
#include <string>


class IDecoder
{
public:
    virtual std::string Decode(const std::string &dataStream) = 0;

    //virtual ~IDecoder() = 0;
};

#endif // IDECODER_H
