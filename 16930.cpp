//running
//BFS

#include<iostream>
#include<deque>
//#include<memory.h>
#define MAX 1000001

//#include <bits/stdc++.h>

int N=0, M=0, K=0, x1=0, y1=0, x2=0, y2=0;
int dcol[4] = {1, 0, 0, -1};    //right, down, up, left
int drow[4] = {0, 1, -1, 0};

class pos{
    public:
        int row;
        int col;

    pos(int _row, int _col) {
        row = _row;
        col = _col;
    }
};

std::deque<pos> dq;

int BFS(std::string* map, std::deque<int>& visited);


int main(){

    //std::ios::sync_with_stdio(0);

    std::cin >> N >> M >> K;
    std::string temp;
    std::string map[N];
    std::deque<int> visited(M*N, MAX);

    for(int i=0; i<N; i++) {
        std::cin >> temp;
        map[i] = temp;
    }
    std::cin >> x1 >> y1 >> x2 >> y2;

    dq.push_back({x1-1, y1-1});
    visited[M*(x1-1)+y1-1] = 0;
    std::cout << BFS(map, visited);


    return 0;
}



int BFS(std::string* map, std::deque<int>& visited) {

    while(!dq.empty()) {

        int row = dq.front().row;
        int col = dq.front().col;
        dq.pop_front();

        if(row == (x2-1) && col == (y2-1)) {
            return visited[M*(x2-1)+(y2-1)];
        }

        //move  //right, down, up, left
        for(int i=0; i<4; i++) {
            for(int j=1; j<=K; j++) {
                int nrow = row+drow[i]*j, ncol = col+dcol[i]*j;
                if( nrow < 0 || nrow > (N-1) || ncol < 0 || ncol > (M-1) || map[nrow][ncol] == '#' || (visited[M*row+col]+1) > visited[M*nrow+ncol] ) break;
                else if(visited[M*nrow+ncol] == MAX) {
                    visited[M*nrow+ncol] = visited[M*row+col]+1;
                    dq.push_back({nrow, ncol});
                }
            }
        }
    }

    return -1;

}