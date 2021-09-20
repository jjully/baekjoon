#include<iostream>

inline void minmax(int N)
{
    int min=0, max=0;
    int temp = 0;
    for(int i=0; i<N; i++)
    {
        std::cin >> temp;
        if(i == 0)
        {
            min = temp;
            max = temp;
        }
        if(temp>max) max = temp;
        if(temp<min) min = temp;
    }
    std::cout << min << ' ' << max;
}

int main()
{
    int N = 0;
    std::cin >> N;
    minmax(N);

    return 0;
}