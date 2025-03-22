#include "Button.h"
#include "WordPadApp.h"

int main() {
	WordPadApp app ;
	//app.AddText("Hello") ;
	//app.AddText("World") ; ;
	//app.InsertText(0, "Welcome") ;


	Button btnAdd{100} ;
	btnAdd.SetClickHandler(&app) ;

	btnAdd.Click() ;
	btnAdd.Click() ;


	Button btnRemove{200} ;
	btnRemove.SetClickHandler(&app) ;
	btnRemove.Click() ;
}
