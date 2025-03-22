#include <iostream>

#include "AddCommand.h"
#include "Button.h"
#include "RemoveCommand.h"
#include "UndoStack.h"
#include "WordPadApp.h"
#include "InsertCommand.h"


//Command Design Pattern
int main() {
    WordPadApp app ;
    //app.AddText("Hello") ;
    //app.AddText("World") ; ;
    //app.InsertText(0, "Welcome") ;

    AddCommand addcmd{&app} ;
    Button btnAdd{100} ;
    btnAdd.SetClickHandler(&addcmd) ;

    btnAdd.Click() ;
    btnAdd.Click() ;

    InsertCommand Insertcmd{&app} ;
    Button btnInsert{300} ;
    btnInsert.SetClickHandler(&Insertcmd) ;

    btnInsert.Click() ;
    btnInsert.Click() ;

    RemoveCommand removecmd{&app} ;
    Button btnRemove{200} ;
    btnRemove.SetClickHandler(&removecmd) ;
    btnRemove.Click() ;

    std::cout << "Starting undo...\n" ;
    while(!UndoStack::IsEmpty()) {
        UndoStack::Pop()->Undo() ;
        std::cin.get() ;
    }
}
