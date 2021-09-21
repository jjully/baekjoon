#include<iostream>
#include<cstdio>
#include<algorithm>

void BSearch(int arr[], int SIZE, int target);

using namespace std;


void BSearch(int arr[], int SIZE, int target) {
    int low = 0;
    int high = SIZE - 1;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == target) {
            //printf("1\n");
            std::cout<<1<<"\n";
            return;
        }
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    //printf("0\n");
    cout<<0<<"\n";
    return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N=0, M=0;

    //scanf("%d", &N);
    cin >> N;
    int arr[N];
    int temp=0;
    for(int i=0; i<N; i++) {
        std::cin >> temp;
        arr[i] = temp;
    }

    //bubble_sort(sample, N);
    sort(arr, arr+N);

    //sorting check
    /*
    for(int i=0; i<N; i++) {
        std::cout << sample[i];
    }
    */

    //scanf("%d", &M);
    cin >> M;
    for(int i=0; i<M; i++) {
        std::cin >> temp;
        //find(sample, N, temp);
        BSearch(arr, N, temp);
    }

    return 0;
}

