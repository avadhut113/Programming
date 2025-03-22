#include "wavedecoder.h"

Wavedecoder::Wavedecoder()
{

}

std::string Wavedecoder::Decode(const std::string &dataStream)
{
    std::string decodedStream{} ;
    for(auto ch : dataStream) {

        decodedStream.push_back( toupper(ch) );
    }
    return decodedStream ;
}
