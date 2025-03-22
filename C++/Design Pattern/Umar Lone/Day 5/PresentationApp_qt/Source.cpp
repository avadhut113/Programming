#include <iostream>

#include "MainApp.h"
#include "SlideData.h"
#include "SlideShowView.h"
#include "TitleView.h"

int main() {
	SlideData data{} ;
	SlideShowView ssview{&data} ;
	TitleView tv{&data} ;
	data.RegisterView(&ssview) ;
	data.RegisterView(&tv) ;

	MainApp app{&data, &ssview} ;

	//app.AddSlide() ;

	app.Load() ;
	//app.RemoveSlide() ;

	//std::cout << "Removing slide directly\n" ;
	//data.RemoveSlide(1) ;

	


	//ssview.Display() ;
	//app.ModifySlide() ;

	//ssview.Display() ;

	/*app.AddSlide() ;
	app.Save() ;
	app.Display() ;*/

}
