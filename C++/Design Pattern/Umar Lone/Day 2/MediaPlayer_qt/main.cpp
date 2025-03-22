
#include "Player.h"
#include "Mp3Player.h"

int main() {

    //Objectpool factory pattern
    // Template factory

    Player player{} ;

    //Mp3Player player{};

    player.AddFile(R"(music001.mp3)") ;
    player.AddFile(R"(sound001.wav)") ;
    player.AddFile(R"(music003.mp3)") ;
    player.Play() ;

}
