#ifndef WAVEDECODER_H
#define WAVEDECODER_H

#include "IDecoder.h"

class Wavedecoder : public IDecoder
{
public:
    Wavedecoder();
    std::string Decode(const std::string &dataStream) override;
    ~Wavedecoder(){}
};

#endif // WAVEDECODER_H
