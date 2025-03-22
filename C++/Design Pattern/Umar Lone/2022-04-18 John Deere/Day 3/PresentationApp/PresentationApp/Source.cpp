#include <iostream>

#include "MainApp.h"
#include "ProjectionView.h"
#include "Slide.h"
#include "SlideData.h"
#include "SlideShowView.h"
#include "TitleView.h"

int main() {

	SlideData data{} ;
	SlideShowView ssview{&data} ;
	TitleView tv{&data} ;
	data.RegisterView(&ssview) ;
	//data.RegisterView(&tv) ;

	MainApp app{&data, &ssview} ;

	//app.AddSlide() ;

	app.Load() ;
	auto slide = data.GetSlide(0) ;
	//slide->SetNotes("Some new note has been added to this slide") ;
	slide->SetTitle("NEW TITLE") ;

	data.Notify(0) ;
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
