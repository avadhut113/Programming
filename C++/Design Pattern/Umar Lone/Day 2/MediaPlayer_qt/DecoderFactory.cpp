#include "DecoderFactory.h"
#include "Mp3Decoder.h"
#include "wavedecoder.h"

DecoderFactory::DecoderFactory()
{

}

IDecoder *DecoderFactory::CreateDecoder(std::string externsion)
{
    if(externsion == ".mp3")
    {
        return new Mp3Decoder{};
    }
    else if(externsion == ".wav")
    {
        return new Wavedecoder{};
    }
    else {
        return nullptr;
    }
}
