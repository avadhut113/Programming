#ifndef _H
#define _H
#include <string>

class IDecoder;

class DecoderFactory
{
public:
    DecoderFactory();
    static IDecoder* CreateDecoder(std::string externsion);
};

#endif // _H
