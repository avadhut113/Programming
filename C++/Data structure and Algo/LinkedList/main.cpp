// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "SinglyLinkedList.hpp"
#include <iostream>

void testSLL()
{
	SinglyLinkedList<int> SLL;
	SLL.insertData(1);
	SLL.insertData(2);
	SLL.insertData(4);
	SLL.insertData(5);
	SLL.insertData(6);

	//Check List issorted
	std::cout << std::boolalpha << SLL.isSorted() << "\n";
	SLL.insert(3, 8);
	std::cout << std::boolalpha << SLL.isSorted() << "\n";

	//insert in sorted list
	SLL.insertInSortedList(8);
	SLL.removeData(8);
	SLL.insertInSortedList(8);
	SLL.insertInSortedList(3);
	SLL.insertInSortedList(0);
	std::cout << SLL;

	//remove data
	SLL.removeData(7);
	SLL.removeData(4);
	std::cout << SLL;

	//remove data using position
	SLL.remove(1);
	SLL.remove(6);
	SLL.remove(3);
	std::cout << SLL;

	//clear list
	SLL.clear();


	SLL.insertData(1);
	std::cout << SLL;
	SLL.removeData(1);
	std::cout << SLL;
}

int main()
{
	testSLL();

	int arr[] = {1,2,3,4,5};
	int (&arr_ref)[std::size(arr)] = arr;

}
