#include<iostream>

int main()
{

    int *row, *col;
    int a=0, b=0;
    row = &a;
    col = &b;
    a++;
    b++;

    std::cout << *row << *col;


    return 0;
}