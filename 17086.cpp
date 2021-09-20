//baby shark2

#include<iostream>
#include<deque>
int dcol[8] = {-1, -1, -1, 0, 1, 1, 1, 0}; //LD L LU U RU R RD D
int drow[8] = {1, 0, -1, -1, -1, 0, 1, 1};
/*
class pos {
    public:
        int row;
        int col;
        int d;

        pos(int _row=0, int _col=0, int _d=0) {
            row = _row;
            col = _col;
            d = _d;
        }
};
*/
int N=0, M=0, max=0;
//std::deque<pos> dq; //{row, col, d}
std::deque<std::pair<int, int> > dq; //{row, col}

void BFS(int* map, int row, int col);

int main() {

    //0. Enter input

    //std::deque<std::pair<int, int> > dq; //{row, col}
    std::cin >> N >> M;
    int map[N*M];
    int temp = 0;
    for(int i=0; i<N; i++) {
        for(int j=0;j<M; j++) {
            std::cin >> temp;
            map[M*i+j] = temp;
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(map[M*i+j] == 0) { BFS(map, i, j); }
        }
    }

    std::cout << max;
    return 0;
}

void BFS(int* map, int startRow, int startCol){

    //int d = 0;
    bool visited[M*N];
    visited[M*startRow+startCol] = true;
    dq.push_back({startRow, startCol, 0});
    //int safe = (M>N)?M:N;
    while(1) {

        if(dq.empty()) {    //idontknow,.,,
            safe = (M>N)? M:N;
            break;
        }
        //check
        int row = dq.front().row;
        int col = dq.front().col;
        int d = dq.front().d;
        //if(safe < d) safe = d;
        dq.pop_front();

        //if(map[M*row+col] == 1) 



        //move

        for(int i=0; i<8; i++) {
            int nrow = row+drow[i], ncol = col+dcol[i];
            if(nrow < 0 || nrow > N-1 || ncol < 0 || ncol > M-1) continue;  //can we go?
            else if(map[M*nrow+ncol] == 1) {
                safe = d+1;
                break;
             } //if we can, is there 1?
            else if(visited[M*nrow+ncol] != true) {
                visited[M*nrow+ncol] = true;
                dq.push_back({nrow, ncol, d+1});
            }
        }
    }

}