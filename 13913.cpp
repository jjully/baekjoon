//hide and seek2
//shortest way == BFS!!

#include<iostream>
#include<queue>
#include<deque>

int N=0, K=0;
//int way = 0, cnt = 0;
int cnt = 0;
std::queue<int> q[2];
std::deque<int> result;
bool visited[100001];
int state[100001];  //0: startpoint 1:-1 2:+1 3:*2
//int max = 100000;
void BFS();

int main() {

    std::cin >> N >> K;

    if(N==K) {
        std::cout << 0 <<'\n' << N;
        return 0;
    }

    q[0].push(N);
    state[N] = 0;   //startpoint
    visited[N] = true;
    BFS();

    int idx = K;

    while(1) {

        result.push_front(idx);
        if(state[idx] == 0){ break; }

        switch(state[idx]) {

            case(1): {  // -1
                idx++;
                break;
            }
            case(2): {
                idx--;
                break;
            }
            case(3): {
                idx/=2;
                break;
            }
        }

    }

    std::cout << cnt << '\n';
    for(int i=0; i<result.size(); i++) {
        std::cout << result[i] << ' ';
    }
    //std::cout << ~



    return 0;
}

void BFS() {

    int idx = 0;
    bool flag = false;
    while(1) {

        if(q[idx].empty()) {
            if( q[!idx].empty() || flag == true ) { return; }
            else {
                idx = !idx;
                cnt++;
            }
        }

        int pos = q[idx].front();
        q[idx].pop();

        if(pos == K) {
            //way++;
            flag = true;
        }
        else {                                                                              //state  //0: startpoint 1:-1 2:+1 3:*2
            //visited[pos] = true;
            int temp0 = pos-1, temp1 = pos+1, temp2 = pos*2;
            if(temp0 >= 0 && temp0 <= 100000 && visited[temp0] == false) {
                visited[temp0] = true;
                state[temp0] = 1;
                q[!idx].push(temp0);
            }
            if( temp1 >= 0 && temp1 <= 100000 && visited[temp1] == false ) {
                visited[temp1] = true;
                state[temp1] = 2;
                q[!idx].push(temp1);
            }
            if( temp2 >= 0 && temp2 <= 100000 && visited[temp2] == false ) {
                visited[temp2] = true;
                state[temp2] = 3;
                q[!idx].push(temp2);
            }

        }

    }


}