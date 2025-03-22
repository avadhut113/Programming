#include "WordPadApp.h"

#include <iostream>

void WordPadApp::AddText(const std::string& text) {
	m_Text += text;
	Display("AddText");
}

void WordPadApp::RemoveText(size_t start, size_t count) {
	m_Text.erase(start, count);
	Display("RemoveText");
}

void WordPadApp::InsertText(size_t start, const std::string& text) {
	m_Text.insert(start, text);
	Display("InsertText");
}

const std::string& WordPadApp::GetText() const {
	return m_Text;
}

void WordPadApp::Display(const char* msg) const {
	std::cout << "[" << msg << "] " << m_Text << '\n';
}

void WordPadApp::Execute(int id) {
	switch (id) {
	case 100: //Add
		AddText("Hello");
		break;
	case 200: //Remove
		RemoveText(0, 4);
		break;

	}

}
