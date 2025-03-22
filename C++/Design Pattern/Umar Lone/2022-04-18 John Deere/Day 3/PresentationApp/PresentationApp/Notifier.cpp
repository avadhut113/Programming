#include "Notifier.h"
#include "View.h"

void Notifier::RegisterView(View* pView) {
	m_Views.push_back(pView) ;
}

void Notifier::UnregisterView(View* pView) {
	m_Views.remove(pView) ;
}

void Notifier::Notify(int part) {
	for(auto view : m_Views) {
		view->Display(part) ;
	}
}