#include<iostream>

void swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int low = left+1, high=right;

    while(low<=high){
        while(arr[low]<pivot)
            low++;
        while(arr[high]>pivot)
            high--;
        
        if(low<=high)
            swap(arr, low, high);
    }

    swap(arr, left, high);
    return high;
}

void Qsort(int arr[], int left, int right)
{
    if(left >= right)
        return;
    
    int pivotIdx = partition(arr, left, right);
    Qsort(arr, left, pivotIdx-1);
    Qsort(arr, pivotIdx+1, right);
}

int main()
{

    int arr[5] = {5, 4, 3, 2, 1};
    Qsort(arr, 0, 4);

    for(int i=0; i<5; i++)
        std::cout<< arr[i];
}