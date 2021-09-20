#include<iostream>

inline void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y =temp;
}

inline void threeSort(int arr[])
{
    int &x = arr[0], &y = arr[1], &z = arr[2];
    int temp = 0;
    if(x < y)
        swap(x, y);

    if((x>=z) && (z>=y))
        swap(y, z);
    else if(z>=x)
    {
    temp = y;
    y = x;
    x = z;
    z = temp;
    }
}

inline void third(int T)
{
    int arr[10];
    for(int i=0; i<T; i++)
    {
        for(int j=0; j<10; j++)
        {
            std::cin >> arr[j];
        }
        threeSort(arr);
        for(int k=3; k<10; k++)
        {
            if(arr[k] > arr[2])
            {
                arr[2] = arr[k];
                threeSort(arr);
            }
        }

        std::cout << arr[2] << std::endl;
    }
}


int main()
{
    int T = 0;
    std::cin  >> T;
    third(T);

    return 0;
}