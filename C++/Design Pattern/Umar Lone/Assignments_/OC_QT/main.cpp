#include <QCoreApplication>
#include "Account.h"

int main(int argc, char *argv[])
{
    Account acc{SAVINGS,100} ;
    QCoreApplication a(argc, argv);

    return a.exec();
}
