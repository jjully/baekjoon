#include<iostream>
#include<random>

#define DWARF_NUM 9

void swap(int&a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high)
{
    int i = (high + 1);
    int &pivot = arr[low];

    for(int j = high; j > low; j--)
    {
        if(arr[j] > pivot)
        {
            i--;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i - 1], pivot);
    return (i - 1);
}

void qsort(int arr[], int low, int high)
{
    int pivot = 0;
    if(low < high)
    {
        pivot = partition(arr, low, high);

        qsort(arr, low, pivot - 1);
        qsort(arr, pivot + 1, high);
    }
 
}

void Snowwhite(int dwarf[], int sum, int ans[])
{

    qsort(dwarf, 0, DWARF_NUM - 1);
/*
    for(int l = 0; l < 9; l++)
    {
        std::cout << dwarf[l] << std::endl;
    }
  */  
    int temp = 0;
    int i = 0, j = 0;
    for(i=0; i<8; i++)
    {
        for(j=(i+1); j<9;j++)
        {
            temp = sum - dwarf[i] - dwarf[j];
            if(temp == 100)
            {
                ans[0] = i;
                ans[1] = j;
                return;
            }
        }
    }

}

int main()
{
    int dwarf[9];
    int ans[2];

    int sum = 0;

    for(int i=0;i<9;i++){
        std::cin >> dwarf[i];
        sum += dwarf[i];
    }

    Snowwhite(dwarf, sum, ans);



    for(int k=0; k<9; k++)
    {
        if((k != ans[0]) && (k != ans[1]))
        {
            std::cout << dwarf[k] << std::endl;
        }

    }

    return 0;
}