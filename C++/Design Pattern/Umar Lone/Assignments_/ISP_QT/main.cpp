#include "IFile.h"
#include "TextFile.h"

void Operate(IFile *pFile) {
    pFile->Open() ;
    pFile->Write() ;
    pFile->Seek(20) ;
    pFile->Close() ;
}

int main() {
    TextFile textFile ;
    Operate(&textFile) ;
    return 0;
}
