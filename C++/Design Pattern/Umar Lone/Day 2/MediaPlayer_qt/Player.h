#pragma once
#include <string>
#include <filesystem>
#include <thread>
#include <IDecoder.h>


class Player
{
	std::vector<std::filesystem::path> m_PlayList{} ;
	std::size_t m_PlayingFileIndex{} ;

    [[nodiscard]] std::ifstream Open(std::size_t index)const ;
    void Read(std::ifstream &input, std::size_t index)/*const*/ ;
public:
	void AddFile(const std::filesystem::path &filePath) ;
	void SelectFile(std::size_t selectedIndex) ;


	void Play() ;
	void Stop() ;
	void Next() ;
	void Previous() ;
    virtual IDecoder* CreateDecorer();
};

