#include<iostream>

int main()
{

    int N=0, K=0;
    std::cin >> N >> K;
    int device[K];  //how many times will device be used
    int order[K];   //using order
    int hole_used[N];   //check whether hole is used or not

    //hole_used를 N개의 별도 data로 저장하지 않고
    //bit mask를 이용하면 for문 없이 이번 차례에 이용하려는 device가
    //이미 꽂혀있는지, 안 꽂혀있는지 바로 확인 가능
    //고쳐서 해보자

    for(int i=0; i<K; i++) { device[i] = 0; }
    //0. input
    for(int i=0; i<K; i++) {
        std::cin >> order[i];
        device[order[i]-1]++;
    }

    for(int i=0; i<N; i++) { hole_used[i] = 0; }

    int count = 0;
    for(int i=0; i<K; i++) {
        //0. if already plugged in, skip
        for(int j=0; j<N; j++) {
            if(hole_used[j] == order[i])
        }
        //1. initiating: put all codes until all holes are full
        if(count < N) {
            device[order[i]-1]--;
            hole_used[count] = order[i];
            count++;
            continue;
        }
        //2. time to plug out and plug in
        //select one which has the least left
        //and plug off
        int least = K;
        int which_hole = 0;
        for(int j=0; j<N; j++) {
            if(device[hole_used[j]-1] < least) {
                least = hole_used[j];
                which_hole = j;
            }
        }
        device[least-1]--;
        hole_used[which_hole] = least;

    }

    return 0;
}