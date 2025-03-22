#include <QCoreApplication>
#include "Form.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //return a.exec();

    Form form{
        L"myclass",
        "My Window",
    } ;


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
}
