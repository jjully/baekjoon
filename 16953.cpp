//A->B
//shortest way == BFS!!

#include<iostream>
#include<queue>

int A=0, B=0, cnt=1;
std::queue<long long> q[2];

void BFS();

int main()
{

    //0. Enter input
    std::cin >> A >> B;
    q[0].push(A);
    BFS();

    std::cout << cnt;

    return 0;
}

void BFS() {

    int idx = 0;
    while(1) {

        if(q[idx].empty()){  //use double buffer queue
            if(q[!idx].empty()) {   //if all q is empty, return;
                cnt = -1;
                return;
            }
            idx = !idx;
            cnt++;
        }
        
        long long cur = q[idx].front();
        q[idx].pop();

        long long temp0 = cur*2, temp1 = cur*10+1;
        if(temp0 == B || temp1 == B) {
            cnt++;
            return;
        }

        if(temp0 < B) {
            q[!idx].push(temp0);
        }
        if(temp1 < B) {
            q[!idx].push(temp1);
        }

    }


}