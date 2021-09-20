#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
#include<queue>
//maze
//find the shortest way = bfs!!!

int N=0, M=0;
int dcol[4] = {1, 0, 0, -1};
int drow[4] = {0, 1, -1, 0};
//std::deque<int> result;
//std::queue<std::pair<int, int> > q1;
//std::queue<std::pair<int, int> > q2;
std::queue<std::pair<int, int> > q;
//void DFS(std::deque<int>& maze, std::deque<bool>& visited, int row, int col, int cnt);
void BFS(std::deque<int>& maze, std::deque<bool>& visited);


int main(){


    //0. Enter input
    std::cin >> N >> M;
    std::deque<std::string> maze_str;
    std::string temp;
    for(int i=0; i<N; i++){
        std::cin >> temp;
        maze_str.push_back(temp);
    }

    //change to int
    std::deque<int> maze(M*N, 0);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(maze_str[i][j] == '1') { maze[M*i+j]=1; }
        }
    }

    //maze check
    /*
    for(int i=0; i<N; i++) {
        std::cout << maze[i] << std::endl;
    }
    */
    std::deque<bool> visited(M*N, false);
    //int cnt = 0;
    q.push(std::make_pair(0, 0));
    visited[0] = true;
    BFS(maze, visited);
    std::cout << maze[M*N-1];

    return 0;
}

void BFS(std::deque<int>& maze, std::deque<bool>& visited) {

    //std::queue<std::pair<int, int> > q;
    //q = q1;

    while(1){

        if(q.empty()) break;

        std::pair<int, int> point = q.front();
        q.pop();

        if(point.first == N-1 && point.second == M-1) {
            return;    
        }

        for(int i=0; i<4; i++) {
            int nrow = point.first+drow[i], ncol = point.second+dcol[i];
            if( nrow < 0 || ncol < 0 || nrow >= N || ncol >= M ) continue; //can we go?
            else if( (maze[M*nrow+ncol] != 0) && (visited[M*nrow+ncol] == false) ) { 
            maze[M*nrow+ncol] = maze[M*point.first+point.second]+1;
            visited[M*nrow+ncol] = true;
            q.push(std::make_pair(nrow, ncol));
            } //if can, is it 1?
        }
    }
}

/*
void DFS(std::deque<std::string>& maze, std::deque<bool>& visited, int row, int col, int cnt) {

    visited[M*row+col] = true;
    cnt++;

    for(int i=0; i<4; i++) {
        int nrow = row+drow[i], ncol = col+dcol[i];
        if( nrow == (N-1) && ncol == (M-1) ) {
            result.push_back(cnt+1);
            break;
        }
        else if( nrow < 0 || ncol < 0 || nrow >= N || ncol >= M ) continue; //can we go?
        else if( (maze[nrow][ncol] == '1') && (visited[M*nrow+ncol] == false) ) { DFS(maze, visited, nrow, ncol, cnt); } //if can, is it 1?
    }

    visited[M*row+col] = false;
}
*/