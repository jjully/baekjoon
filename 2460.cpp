#include<iostream>

inline void maxppl(){

    int max = 0;
    int cur = 0;
    int in = 0;
    int out = 0;
    for(int i=0;i<10;i++)
    {
        std::cin >> out >> in;
        cur = cur - out + in;
        if(max<cur) max = cur;
    }

    std::cout << max;

}

int main()
{

    maxppl();

    return 0;
}