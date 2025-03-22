#pragma once
#include <string>

class Slide
{
	std::string m_Title{} ;
	std::string m_Content{} ;
	std::string m_Notes{} ;
public:
	Slide() = default ;
	Slide(const std::string& title, const std::string& content, const std::string& notes);
	const std::string& GetTitle() const;
	void SetTitle(const std::string& title);
	const std::string& GetContent() const;
	void SetContent(const std::string& content);
	const std::string& GetNotes() const;
	void SetNotes(const std::string& notes);
};

