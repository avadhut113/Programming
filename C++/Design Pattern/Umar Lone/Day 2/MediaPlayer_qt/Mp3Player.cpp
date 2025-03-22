#include "Mp3Player.h"
#include "Mp3Decoder.h"

Mp3Player::Mp3Player()
{

}

IDecoder *Mp3Player::CreateDecorer()
{
    return new Mp3Decoder();
}
