#include <deque>
#include <iostream>
#include <map>

#include "AddressBook.h"
#include "Contact.h"
#include "Row.h"

//Objectpool pattern
class RowFactory {
	std::vector<Row*> m_Rows{} ;
public:
	Row * CreateRow(const std::string &name, const std::string &num) {
		Row *pRow{} ;
		for(auto row : m_Rows) {
			if(!row->IsVisible()) {
				std::cout << "^" ;
				pRow = row ;
				break ;
			}
		}
		if(!pRow) {
			std::cout << "+" ;
			pRow = new Row{} ;
		}
		pRow->SetLine01(name) ;
		pRow->SetLine02(num) ;
		m_Rows.push_back(pRow) ;
		return pRow ;
	}
};
int main() {
	AddressBook book{} ;
	book.LoadDb("contacts.txt") ;
	std::deque<Row *> rows{} ;
	size_t begin = 0 ;
	size_t end = 5 ;

	RowFactory factory ;
	for (size_t i = begin; i < end; ++i) {
		auto contact = book.GetContact(i);
		auto row = factory.CreateRow(contact->GetName(), contact->GetPhone() );
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
		auto row = factory.CreateRow(contact->GetName(), contact->GetPhone() );
		row->Render();
		rows.push_back(row);
		std::cin.get();
		system("cls") ;

		
	}

	std::cout << "Total objects:" << Row::object_count << '\n' ;
	return 0 ;
}


template<typename T>
class Factory {
public:
	T *Create() {
		return new T{} ;
	}
};


void UseFactory() {
	Factory<Row> f ;
	auto r = f.Create() ;
}

template<typename T, typename...Args>
T * Create(Args...args) {
	return new T{args...} ;
}

void UsingFunction() {
	auto p = Create<int>(6) ;

	auto ptr = std::make_shared<int>(5) ;

	std::map<int, std::string> m ;
	m.insert(std::pair<int, std::string>(1, "Umar")) ;
	m.insert(std::make_pair(1, "dfsdf")) ;

	


}