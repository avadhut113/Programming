#include "Player.h"

#include <iostream>
#include <fstream>
#include <random>
#include <thread>

#include "Mp3Decoder.h"

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

void Player::Read(std::ifstream& input)const {
	using namespace std::chrono_literals ;
	std::string dataStream{} ;
	auto pDecoder = new Mp3Decoder{} ;
	while(std::getline(input, dataStream)) {
		auto decodedStream = pDecoder->Decode(dataStream);
		for(auto ch : decodedStream) {
			std::cout << ch ;
			std::this_thread::sleep_for(1us) ;
		}
	}
	delete pDecoder ;
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
		Read(inputStream) ;

		std::cout << "\n\n" ;
	}
	m_PlayingFileIndex = 0 ;
}

