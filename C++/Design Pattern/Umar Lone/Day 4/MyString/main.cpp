#include <QCoreApplication>
#include "IOperation.h"
#include "MyString.h"

class ToUpper : public IOperation
{
public :
    void operate(MyString& str) {
        for(int i = 0; i< str.GetLength() ; i++) {
            str[i] = std::toupper(str[i]);
        }
    }
};

int main(int argc, char *argv[])
{

    MyString mystr;
    mystr.AddString("Avadhut");
    mystr.AddString("Patil");
    mystr.accept(new ToUpper);

    std::cout << mystr.GetString() << std::endl;
    return 0;
}
