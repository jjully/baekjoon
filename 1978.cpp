#include<iostream>
#include<cmath>

int main()
{
    int N=0;
    std::cin >> N;
    
    int *arr = new int[N];
    int count = N;

    //input data
    for(int i=0; i<N; i++)
        std::cin >> arr[i];
    
    for(int j=0; j<N; j++)
    {
        if(arr[j] == 1)
        {
            count--;
            continue;
        }
        for(int k=2; k<=sqrt(arr[j]); k++)
        {
            if(arr[j] % k == 0)
            {
                count--;
                break;
            }
        }
    }

    std::cout << count << std::endl;
    return 0;
}