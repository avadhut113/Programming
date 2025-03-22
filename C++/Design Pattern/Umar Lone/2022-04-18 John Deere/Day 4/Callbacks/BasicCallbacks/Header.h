#pragma once
#include <iostream>

class Interface {
public:
	virtual void Found(bool has_found) = 0;
};

class FindDialog {
	Interface* m_Itf;
public:
	FindDialog(Interface* itf)
		: m_Itf{ itf } {
	}
	void Set(Interface* p) {
		m_Itf = p;
	}
	void Find() {
		std::cout << "[FindDialog] Calling method in some other class -> ";
		m_Itf->Found(true);
	}
};


class Notepad : public Interface {
public:
	void MethodB() {
		std::cout << "[Notepad] method called\n";
	}
	void Found(bool has_found) override {
		MethodB();
	}
};




class PowerPoint : public Interface {
public:
	void MethodC() {
		std::cout << "[PowerPoint] method called\n";
	}
	void Found(bool has_found) override {
		MethodC();
	}
};
