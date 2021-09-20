#include<iostream>

void divisor() {

    int a, b;
    //std::cout <<"Enter two numbers" << std::endl;
    std::cin >> a >> b;

    int count = 0;

    for(int i=1; i<=a; i++) {
        if(a%i == 0) count++;
        if(count == b) {
        std::cout << i << std::endl;
        return;
        }
    }

    std::cout << 0 << std::endl;


}

int main()
{

    divisor();

    return 0;
}