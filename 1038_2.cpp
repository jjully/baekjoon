#include<iostream>
#include<queue>

#define MAX 1000001
int N=0;
long long decreasingNum[MAX];
std::queue<long long> q;
long long find(int idx) {

    while(idx < N)
    {
        if(q.empty())
            break;

        long long temp = q.front();
        q.pop();

        //check last no. of temp
        if(temp % 10 == 0) continue;
        else {
            int lastNum = temp % 10;
            for(int i=0; i<lastNum; i++) {
                decreasingNum[++idx] = temp * 10 + i;
                q.push(temp * 10 + i);
            }
        }
    }

    if(idx >= N)
        return decreasingNum[N];
    else
        return -1;



}

int main() {

    std::cin >> N;
    int idx = 9;

    if(N<=10) {
        std::cout << N;
        return 0;
    }

    for(int i = 1; i < 10; i++) {
        decreasingNum[i] = i;
        q.push(i);
    }

    std::cout << find(idx);


    return 0;
}