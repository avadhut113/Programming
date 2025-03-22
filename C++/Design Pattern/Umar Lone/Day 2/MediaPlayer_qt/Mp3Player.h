#ifndef MP3PLAYER_H
#define MP3PLAYER_H

#include "Player.h"

class Mp3Player : public Player
{
public:
    Mp3Player();
    ~Mp3Player(){}


    // Player interface
public:
    IDecoder *CreateDecorer();
};

#endif // MP3PLAYER_H
