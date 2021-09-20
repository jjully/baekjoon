//avoiding food waste
//need to check all elements = DFS

#include<iostream>
#include<deque>
#include<stack>

int drow[4] = {0, 1, -1, 0};    //right, down, up, left
int dcol[4] = {1, 0, 0, -1};

void DFS(std::deque<int>& map, std::deque<bool>& visited, int& cnt);

int N=0, M=0, K=0;
std::stack<std::pair<int, int> > s;

int main(){

    //0. Enter input
    std::cin >> N >> M >> K;

    int tempr=0, tempc=0;
    std::deque<int> map(N*M, 0);
    for(int i=0; i<K; i++) {
        std::cin >> tempr >> tempc;
        map[M*(tempr-1)+tempc-1] = 1;
    }

    std::deque<bool> visited(N*M, false);
    int max=0;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if( (visited[M*i+j] == false) && (map[M*i+j] == 1) ){
                int cnt = 1;
                s.push({i, j});
                visited[M*i+j] = true;
                DFS(map, visited, cnt);
                if(max < cnt) max = cnt;
            }
        }
    }

    std::cout << max;

    return 0;
}


void DFS(std::deque<int>& map, std::deque<bool>& visited, int& cnt) {

    if(s.empty()) return;

    int row = s.top().first;
    int col = s.top().second;
    s.pop();

    for(int i=0; i<4; i++) {    //right, down, up, left
        int nrow = row+drow[i], ncol = col+dcol[i];
        if( nrow < 0 || nrow >= N || ncol < 0 || ncol >= M ) continue; //can we go?
        else if( (map[M*nrow + ncol] == 1) && (visited[M*nrow + ncol] == false) ){ //if can, is it food waste and not visited yet?
            cnt++;
            visited[M*nrow + ncol] = true;
            s.push({nrow, ncol});
            DFS(map, visited, cnt);
        }
    }


}