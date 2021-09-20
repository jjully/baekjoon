#include<iostream>
#include<cmath>

#define MAX 10000
void findPrime(int M, int N);

int main()
{

    int M=0, N=0;
    std::cin >> M >> N;
    findPrime(M, N);

    return 0;
}

void findPrime(int low, int high)
{
    int sum = 0, min = MAX;
    bool primeFlag = true;

    for(int i=low; i<=high; i++)
    {
        primeFlag = true;
        if(i==1)
            continue;

        for(int j=2; j<=sqrt(i); j++)
        {
            if(i%j == 0)
                primeFlag = false;
        }

        if(primeFlag)
        {
            sum+=i;
            if(i < min)
                min = i;
        }
    }

    if(sum == 0)
        std::cout << -1 << std::endl;
    else
        std::cout << sum << '\n' << min << std::endl;
}
