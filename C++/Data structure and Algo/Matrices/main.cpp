// Matrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DiagonalMatrix.h"
#include "LowerTriangularMatrix.h"


int main()
{
	//DiagonalMatrix matrix(5);
	//for (int i = 0; i < 5; i++) {
	//	for (int j = 0; j < 5; j++) {
	//		matrix.set(i + j, i, j);
	//	}
	//}
	//matrix.display();


	LowerTriangularMatrix matrix(5);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			matrix.set_rows(i + j, i, j);
		}
	}
	matrix.display_rowwise();

	std::cout << "\n\n\n";

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			matrix.set_columns(i + j, i, j);
		}
	}
	matrix.display_columnwise();
}

