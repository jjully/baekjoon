//hide and seek2
//shortest way == BFS!!

#include<iostream>
#include<queue>

int N=0, K=0;
int way = 0, cnt = 0;
std::queue<int> q[2];
bool visited[200001];
//int max = 100000;
void BFS();

int main() {

    std::cin >> N >> K;

    int input = N;
    q[0].push(input);
    while(input < K) {
        input*=2;
        if(input == K) {
            std::cout << 0;
            return 0;
        }

        q[0].push(input);
        visited[input] = true;
        //input*=2;

    }

    BFS();

    //std::cout << cnt << '\n' << way;
    std::cout << cnt;


    return 0;
}

void BFS() {

    int idx = 0;
    //ol flag = false;
    while(1) {

        if(q[idx].empty()) {
            if( q[!idx].empty() ) { return; }
            else {
                idx = !idx;
                cnt++;
            }
        }

        int pos = q[idx].front();
        q[idx].pop();


        if( pos == K ) {
            return;
        }
        else {

            int temp0 = pos-1, temp1 = pos+1;
            //int temp2 = temp0*2, temp3 = temp1*2;

            if(temp0 >= 0 && temp0 <= 100000 && visited[temp0] == false) {
                visited[temp0] = true;
                q[!idx].push(temp0);
                //temp0*=2;
                while((temp0 != 0) && temp0 <= K) {
                    temp0*=2;
                    if(visited[temp0] == false) {
                        q[!idx].push(temp0);
                        visited[temp0] = true;
                    }
                    //temp0*=2;
                }
            }


            if( temp1 >= 0 && temp1 <= 100000 && visited[temp1] == false ) {
                visited[temp1] = true;
                q[!idx].push(temp1);
                //temp1*=2;
                while((temp1 != 0) && (temp1 <= K)) {
                    temp1*=2;
                    if(visited[temp1] == false) {
                        q[!idx].push(temp1);
                        visited[temp1] = true;
                    }
                    temp1*=2;
                }
            }

        }

    }



}