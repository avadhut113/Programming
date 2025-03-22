#pragma once
#include <string>
#include <vector>


class Player
{
	std::vector<std::string> m_PlayList{} ;
	std::size_t m_PlayingFileIndex{} ;
public:
	void AddFile(const std::string &filePath) ;
	void SelectFile(std::size_t selectedIndex) ;
	[[nodiscard]] std::ifstream Open(std::size_t index)const ;
	void Read(std::ifstream &input)const ;
	void Play() ;
	void Stop() ;
	void Next() ;
	void Previous() ;
};

