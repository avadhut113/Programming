
#include <iostream>

#include "Header.h"


int main() {
	Notepad b;
	FindDialog a{ &b };

	a.Find();

	a.Set(new PowerPoint);
	a.Find();
}
