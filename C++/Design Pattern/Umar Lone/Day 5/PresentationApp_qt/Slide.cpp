#include "Slide.h"

Slide::Slide(const std::string& title, const std::string& content, const std::string& notes): m_Title{title},
	m_Content{content},
	m_Notes{notes} {
}

const std::string& Slide::GetTitle() const {
	return m_Title;
}

void Slide::SetTitle(const std::string& title) {
	m_Title = title;
}

const std::string& Slide::GetContent() const {
	return m_Content;
}

void Slide::SetContent(const std::string& content) {
	m_Content = content;
}

const std::string& Slide::GetNotes() const {
	return m_Notes;
}

void Slide::SetNotes(const std::string& notes) {
	m_Notes = notes;
}
