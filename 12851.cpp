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

    if(N==K) {
        std::cout << 0 <<'\n' << 1;
        return 0;
    }

    q[0].push(N);
    visited[N] = true;
    BFS();

    std::cout << cnt << '\n' << way;



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
            way++;
            flag = true;
        }
        else {
            visited[pos] = true;
            int temp0 = pos-1, temp1 = pos+1, temp2 = pos*2;
            if(temp0 >= 0 && temp0 <= 100000 && visited[temp0] == false) {
                //if(temp0 != K) visited[temp0] = true;
                q[!idx].push(temp0);
            }
            if( temp1 >= 0 && temp1 <= 100000 && visited[temp1] == false ) {
                //if(temp1 != K) visited[temp1] = true;
                q[!idx].push(temp1);
            }
            if( temp2 >= 0 && temp2 <= 100000 && visited[temp2] == false ) {
                //if(temp2 != K) visited[temp2] = true;
                q[!idx].push(temp2);
            }

        }

/*
        int temp0 = pos-1, temp1 = pos+1, temp2 = pos*2;
        if( (temp0 == K || temp1 == K || temp2 == K)  && (max > cnt) ) {  //if arrived and still have time
            max = ++cnt;
            if(temp0 == K) way++;
            if(temp1 == K) way++;
            if(temp2 == K) way++;
        }
        else if(max == cnt) continue; //if not arrived or arrived but already on max time
        else {    //if not arrived but still have time
            cnt++;
            if( temp0 >= 0 && temp0 <= 100000 && visited[temp0-1] == false ) {
                visited[temp0-1] = true;
                q.push({temp0, cnt});
            }
            if( temp1 >= 0 && temp1 <= 100000 && visited[temp1-1] == false ) {
                visited[temp1-1] = true;
                q.push({temp1, cnt});
            }
            if( temp2 >= 0 && temp2 <= 100000 && visited[temp2-1] == false ) {
                visited[temp2-1] = true;
                q.push({temp2, cnt});
            }        
        }
*/
    }


}