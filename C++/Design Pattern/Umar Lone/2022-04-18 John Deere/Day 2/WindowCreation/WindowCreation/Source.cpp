#include "Form.h"
#include <sstream>
int main() {

    FormBuilder creator ;

    Form f = creator.SetX(100) 
    .SetY(100) 
    .SetNWidth(300) 
    .SetNHeight(600)
	.Build() ;

    //Form f = creator.Build() ;

    std::cout
		<< 1 
		 << 2 
		 << 3 ;

	/*Form form{
		L"myclass",
		"My Window",
        200, 0, 100, 100
	} ;*/
    /*
     * uid, pwd, dbname, table, connection security
     */


#pragma region MessageLoop/Event Loop
	MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, nullptr, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
#pragma endregion 
}


class QForm {
    void Init() {
	    /*
	     * This is the initialization code
	     */
    }
public:
    //QForm(int x,int y, char ch, float f, double a,int max){
	   //Init() ;
    //}
    //QForm(int x,int y, char ch) {
	   //Init() ;
    //}
    //QForm(float f, double a) {
	   //Init() ;
    //}

     QForm(int x=0,int y=0, char ch='a', float f =0.f, double a = 1.1,int max = 255){
    }
};