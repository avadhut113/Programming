#include "MainApp.h"

int main() {
	MainApp app{} ;
	app.Load() ;
	app.Display() ;
	app.ModifySlide() ;

	app.Display() ;
	/*app.AddSlide() ;
	app.Save() ;
	app.Display() ;*/

}
