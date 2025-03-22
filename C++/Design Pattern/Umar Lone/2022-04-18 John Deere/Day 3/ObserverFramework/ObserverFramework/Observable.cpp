#include "Observable.h"

#include "Observer.h"

void Observable::Attach(Observer* ob) {
	m_Observers.push_back(ob) ;
}

void Observable::Detach(Observer* ob) {
	m_Observers.remove(ob) ;
}

void Observable::Notify(void* pInfo) {
	for(auto ob : m_Observers) {
		ob->OnUpdate(pInfo) ;
	}
}
