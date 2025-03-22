
#include "Player.h"
int main() {
	Player player{} ;
	player.AddFile(R"(music001.mp3)") ;
	player.AddFile(R"(music002.mp3)") ;
	player.AddFile(R"(music003.mp3)") ;
	player.Play() ;

}
