#include "Player.h"

#include <iostream>
#include <fstream>
#include <random>
#include <thread>
#include "DecoderFactory.h"

void Player::AddFile(const std::filesystem::path& filePath) {
	m_PlayList.push_back(filePath) ;
}

void Player::SelectFile(std::size_t selectedIndex) {
	m_PlayingFileIndex = selectedIndex ;
}



void Player::Stop() {
	//DUMMY METHOD
}

void Player::Next() {
	//DUMMY METHOD

}

void Player::Previous() {
    //DUMMY METHOD
}

IDecoder *Player::CreateDecorer()
{
    return nullptr;
}


std::ifstream Player::Open(std::size_t index)const {
	std::ifstream currentFile{} ;
	const auto &path = m_PlayList[index] ;
	if(!std::filesystem::exists(path)) {
		std::cout << "Invalid file path\n" ;
		return {} ;
	}
	currentFile.open(path) ;
	if(!currentFile) {
		std::cout << "Could not open file for reading\n" ;
	}
    return currentFile ;
}

void Player::Read(std::ifstream& input,std::size_t index)/*const*/ {
	using namespace std::chrono_literals ;
	std::string dataStream{} ;
    //auto IDecoder = CreateDecorer();      // virtual constructor is the alias for factory method.

    const auto &path = m_PlayList[index];
    std::string extension = path.extension().u8string();
    auto IDecoder  = DecoderFactory::CreateDecoder(extension);

	while(std::getline(input, dataStream)) {
        auto decodedStream = IDecoder->Decode(dataStream);
		for(auto ch : decodedStream) {
			std::cout << ch ;
            std::this_thread::sleep_for(20ms) ;
		}
	}
    delete IDecoder ;
}

void Player::Play() {
	if(m_PlayList.empty()) {
		std::cout << "Playlist is empty\n" ;
		return ;
	}
	for(std::size_t current = m_PlayingFileIndex ; current < m_PlayList.size() ; ++current) {
		auto inputStream = Open(current) ;
		if(!inputStream) {
			continue ;
		}
		std::cout << "Playing : " << m_PlayList[current] << '\n' ;
        Read(inputStream, current) ;

		std::cout << "\n\n" ;
	}
	m_PlayingFileIndex = 0 ;
}

