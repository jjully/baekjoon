#include<iostream>

int main() {

    int cnt=0;
    int N=0, M=0;
    std::cin >> N >> M;
    int A[N];
    int temp=0;
    for(int i=0; i<N; i++) {
        std::cin >> temp;
        A[i] = temp;
    }

    for(int i=0; i<N; i++) {
        int idx = i, value = 0;
        while(idx <N) {
            value += A[idx];
            idx++;
            if(value == M) {
                cnt++;
                break;
            }
            else if(value > M) {
                break;
            }
            else continue;
        }
    }

    std::cout << cnt;

    return 0;
}