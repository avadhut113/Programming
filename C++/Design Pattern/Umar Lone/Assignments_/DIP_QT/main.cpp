#include <cstdlib>
#include <ctime>

#include "Controller.h"

int main() {
    srand(time(nullptr)) ;
    Controller controller{50, 100} ;
    controller.Regulate() ;
    controller.Regulate() ;
    controller.Regulate() ;
    controller.Regulate() ;
    controller.Regulate() ;
    controller.Regulate() ;

    return 0;
}
