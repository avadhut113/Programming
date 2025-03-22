#include <deque>
#include <iostream>

#include "AddressBook.h"
#include "Contact.h"
#include "Row.h"


int main() {
	AddressBook book{} ;
	book.LoadDb("contacts.txt") ;
	std::deque<Row *> rows{} ;
	size_t begin = 0 ;
	size_t end = 5 ;

	for (size_t i = begin; i < end; ++i) {
		auto contact = book.GetContact(i);
		auto row = new Row{ contact->GetName(), contact->GetPhone() };
		row->Render();
		rows.push_back(row);
	}
	std::cin.get();
	system("cls");

	while(end < book.Count()) {
		rows[begin]->SetVisibility(false) ;
		++begin ;
		++end ;
		size_t i{begin} ;
		for( ; i < rows.size() ; ++i) {
			rows[i]->Render() ;
		}
		auto contact = book.GetContact(i);
		auto row = new Row{ contact->GetName(), contact->GetPhone() };
		row->Render();
		rows.push_back(row);
		std::cin.get();
		system("cls") ;

		
	}

	std::cout << "Total objects:" << Row::object_count << '\n' ;
	return 0 ;
}
 