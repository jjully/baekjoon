#include<iostream>

int findsum(int index)
{
    int n=0;
    do
    {
        n++;
    } while (index >= (n * (n+1) / 2));

    n--;
    index = index - (n * (n+1) / 2);
    int ans = n * (n+1) * (2*n+1) / 6 + (n+1) * index;

    return ans;
    
}

int main()
{

    int n=0, m=0;
    std::cin >> n >> m;
    std::cout << (findsum(m) - findsum(n - 1));

    return 0;
}