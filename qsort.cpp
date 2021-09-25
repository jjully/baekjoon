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
    int low=left+1, high=right;

    while(low<=high) {
        while(arr[low] < pivot)
            low++;
        while(arr[high] > pivot)
            high--;

        if(low<=high)
            swap(arr, low, high);
    }

    swap(arr, left, high);
    return high;
}

void qsort(int arr[], int left, int right) {

    if(left>=right) return;

    int pivot = partition(arr, left, right);
    qsort(arr, left, pivot-1);
    qsort(arr, pivot+1, right);
}

int main()
{

    int N=0;
    std::cin >> N;
    int arr[N];

    for(int i=0; i<N; i++)
        std::cin >> arr[i];

    qsort(arr, 0, N-1);

    for(int i=0; i<N; i++)
        std::cout << arr[i] << ' ';


    return 0;
}