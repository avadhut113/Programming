#pragma once
#include <string>
#include <vector>

class ProjectionView
{
	std::vector<std::string> m_Data{} ;
public:
	void AddData(const std::string &data) ;
	void Project() ;
	size_t Size()const ;
	void Clear() ;
};

