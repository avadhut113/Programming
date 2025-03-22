#pragma once
#include <string>

class Row
{
	std::string m_Line01 ;
	std::string m_Line02 ;
	bool m_Visible{true} ;
public:
	inline static size_t object_count = 0 ;
	bool IsVisible()const ;
	void SetVisibility(bool visible) ;
	Row();
	Row(const std::string& line01, const std::string& line02);
	const std::string& GetLine01() const;
	void SetLine01(const std::string& line01);
	const std::string& GetLine02() const;
	void SetLine02(const std::string& line02);
	void Render() ;
};

