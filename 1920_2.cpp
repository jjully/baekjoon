#include<iostream>
#include<stdio.h>
#include<queue>
void find(int* sample, int SIZE, int x);
void bubble_sort(int* sample, int N);
int BSearch(int arr[], int SIZE, int target);

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N=0, M=0;

    priority_queue<int, vector<int>, greater<int> > pq;

    scanf("%d", &N);
    int sample[N];
    int temp=0;
    for(int i=0; i<N; i++) {
        std::cin >> temp;
        //sample[i] = temp;
        pq.push(temp);

    }

    for(int i=0; i<N; i++) {
        sample[i] = pq.top();
        pq.pop();
    }
    //bubble_sort(sample, N);

    //sorting check
    /*
    for(int i=0; i<N; i++) {
        std::cout << sample[i] << std::endl;
        //std::cout << pq.top();
        //pq.pop();
    }
    */

    scanf("%d", &M);
    for(int i=0; i<M; i++) {
        std::cin >> temp;
        //find(sample, N, temp);
        if(BSearch(sample, N, temp) == -1) {
            printf("0\n");
        }
        else {
            printf("1\n");
        }
    }

    return 0;
}

void bubble_sort(int* sample, int N) {

    for(int i=1; i<N; i++) {
        int temp = sample[i];
        for(int j=0; j<i; j++) {
            if(sample[i] < sample[j]) {
                for(int k=i; k>j; k--) {
                    sample[k] = sample[k-1];
                }
                sample[j] = temp;
            }
        }
    }


}

void find(int* sample, int SIZE, int x) {

    int left = 0, right = SIZE-1;
    int mid = (left+right)/2;
    while(left <= right) {

        if(sample[mid] == x) {
            printf("1\n");
            return;
        }
        else if(x < sample[mid]) {
            right = mid-1;
        }
        else // x > sample[mid]
            left = mid+1;
    }

    printf("0\n");

}

int BSearch(int arr[], int SIZE, int target) {
    int low = 0;
    int high = SIZE - 1;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}