#include "Person.h"


class CPerson::CPersonImpl
{
public:
	CPersonImpl() = default;
	~CPersonImpl() = default;

	void greet(CPerson* p) {
		std::cout << "Person name is " << p->get_name();
	}
};

CPerson::CPerson() : impl(new CPersonImpl())
{

}

CPerson::~CPerson()
{
	delete impl;
}

void CPerson::greet()
{
	impl->greet(this);
}
