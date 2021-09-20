#include<iostream>
#include<deque>
//#define MAX 100
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int visited[100][100];

void DFS(int x, int y, std::deque<char>* graph, int& cnt, int N, int M) {
    cnt++;
    visited[x][y] = 1;

    for(int i=0; i<4; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if( nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
        if(!visited[nx][ny] && graph[nx][ny] == graph[x][y]) DFS(nx, ny, graph, cnt, N, M);
    }
}

int main() {

    int N, M;
    std::cin >> N >> M;
    std::deque<char> graph[M];
    std::deque<int> result(2, 0);

    for(int i=0; i<M; i++){
        std::string str;
        std::cin >> str;
        for(char c: str) graph[i].push_back(c);
    }

    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            int cnt = 0;
            if(!visited[i][j]) {
                DFS(i, j, graph, cnt, N, M);
                if(graph[i][j] == 'W') result[0] += cnt*cnt;
                else result[1] += cnt*cnt;
            }
        }
    }

    std::cout << result[0] << ' ' << result[1];

    return 0;
}