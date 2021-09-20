//hide and seek2
//shortest way == BFS!!

#include<iostream>
#include<queue>

int N=0, K=0;
int way = 0, cnt = 0;
std::queue<int> q[2];
bool visited[100001];
//int max = 100000;
void BFS();

int main() {

    std::cin >> N >> K;

    int input = N;
/*
    while(input*2 <= 100000) {
        
        if(input == K) {
            std::cout << 0;
            return 0;
        }

        q[0].push(input);
        visited[input] = true;
        input*=2;
    }
*/
    q[0].push(N);
    visited[N] = true;
    BFS();

    //std::cout << cnt << '\n' << way;
    std::cout << cnt;


    return 0;
}

void BFS() {

    int idx = 0;

    while(1) {
        
        if(q[idx].empty()) {    //change queue
            idx = !idx;
            cnt++;
        }
        

        int pos = q[idx].front();
        q[idx].pop();


        if( pos == K ) {
            return;
        }
        else {

            int temp0 = pos-1, temp1 = pos+1, temp2 = pos*2;
            if( (temp2 <= 100000) && (visited[temp2] == false) ){
                q[idx].push(temp2);
                visited[temp2] = true;
            }
            if( (temp0 >= 0) && (visited[temp0] == false) ){
                q[!idx].push(temp0);
                visited[temp0] = true;
            }
            if( (temp1 <= 100000) && (visited[temp1] == false) ){
                q[!idx].push(temp1);
                visited[temp1] = true;

            }

        }

    }



}