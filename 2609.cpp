#include<iostream>

int GCD(int n, int m);
int LCM(int n, int m);

int main()
{

    int n=0, m=0;
    std::cin >> n >> m;

    std::cout << GCD(n, m) << '\n' << LCM(n, m);

    return 0;
}


int GCD(int n, int m)
{
    if(n > m)
    {
        int temp = n;
        n = m;
        m = temp;
    }

    for(int i=n; i>0 ;i--)
    {
        if((n%i == 0) && (m%i == 0))
            return i;
    }

    std::cout << "Error: return -1" << std::endl;
    return  -1;
}

int LCM(int n, int m)
{
    int gcd = GCD(n, m);
    int x = (n/gcd);
    int y = (m/gcd);

    return gcd * x * y;

}
