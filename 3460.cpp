#include <iostream>

inline void binary (int T) {

    int n = 0;
    int quotient = 0;
    int remainder = 0;

    for(int i=0; i<T; i++)
    {
        std::cin >> quotient;
        int j = 0;
        while(1)
        {
            remainder = quotient % 2;
            quotient = quotient / 2;
            if(remainder) {
                std::cout << j << ' ';
            }
            if(quotient!=0)
            {
                //std::cout << ' ';
            }
            else break;

            j++;
        }

        //std::cout << std::endl;
    }

}


int main(){

    int T = 0;
    std::cin >> T;

    binary(T);

    return 0;
}