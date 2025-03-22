// Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//"india is my country"
//"Country my is india"

//void print_reverse(char* ch)
//{
//    if (*ch == '\0')
//        return;
//
//    char c = *ch;
//    print_reverse(++ch);
//    std::cout << c;
//}

void print_reverse(char str[], int index)
{
    if ( str[index] == '\0')
        return;

    print_reverse(str,index+1);
    std::cout << str[index];
}

void do_reverse(char str[], int first,int end)
{
    if (first > end)
        return;

    do_reverse(str, first + 1, end-1);
    std::swap(str[first], str[end]);
}

void do_rev(char str[])
{
    int size = strlen(str);
    for (int first = 0; first < size / 2; first++) {
        std::swap(str[first], str[size - first - 1]);
    }
}

int main()
{
    char str[] = "Hello World!";
    //int size = sizeof(str) ;
    
    //do_rev(str);
    do_reverse(str, 0, strlen(str) - 1);
    std::cout << str << std::endl;

    //do_reverse(str, 0, size-1);

    //std::cout << str << std::endl;

    //print_reverse(str, 0);
    return 0;
}
