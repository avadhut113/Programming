#pragma once
#include "IDecoder.h"

class Mp3Decoder : public IDecoder
{
public:
    std::string Decode(const std::string &dataStream) override;
    ~Mp3Decoder(){}
};

