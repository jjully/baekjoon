//baekjoon 16234

//DFS
//visited 사용
//모든 나라에 들리긴 해야함
//union과 sum을 이용해서 union엔 현재 연합에 포함된 국가 위치, sum에는 그 값의 합
//DFS로 다 찾고 나면 sum/union.size()해서 값을 연합에 포함된 국가들에 대입해주고, 넘어감
//연합이 하나라도 생기면 flag=true, 반복
//한바퀴다돌고나면 계속함
//연합이 더 이상 안 생기면 종료

#include<iostream>
#include<vector>
#include<cmath>

int N=0, L=0, R=0;
int drow[] = {1, 0, -1, 0}; //S W N E
int dcol[] = {0, -1, 0, 1};

std::vector<std::vector<int> >map;

//fcns
void Input();
void solution();
template <typename T>
void v2DInit(std::vector<std::vector<T> >&v, int row, int col, T val);
void DFS(std::vector<std::vector<bool> >& visited, 
        std::vector<std::pair<int, int> >& Union, int& sum, int row, int col);
void MovePopulation(std::vector<std::pair<int, int> >& Union, int& sum);


void Input() {
    std::cin >> N >> L >> R;
    map.resize(N);
    for(int i=0; i<N; i++) {
        map[i].resize(N, 0);
    }

    for(int i=0; i<N; i++) {            //save map info.
        for(int j=0; j<N; j++) {
            std::cin >> map[i][j];
        }
    }
}

void makingUnion(bool& flag) {

    flag = false;
    std::vector<std::vector<bool> >visited;
    v2DInit(visited, N, N, false);  //reset visited info.
    for(int i=0; i<N; i++) {    //for all points
        for(int j=0; j<N; j++) {
            std::vector<std::pair<int, int> > Union;
            int sum=0;
            DFS(visited, Union, sum, i, j);
            if(Union.size() > 1) {
                flag = true; //if there exists more than one union, flag = true
                MovePopulation(Union, sum);
            }
        }
    }

}


void DFS(std::vector<std::vector<bool> >& visited, 
        std::vector<std::pair<int, int> >& Union, int& sum, int row, int col) {    //inside of one day

    if(visited[row][col] == true) return;
    visited[row][col] = true;
    sum += map[row][col];
    Union.push_back({row, col});

    for(int i=0; i<4; i++) {    //S W N E
        int nextRow = row+drow[i];
        int nextCol = col+dcol[i];
        if( nextRow<0 || nextRow>=N || nextCol<0 || nextCol>=N ) continue;
        else if( visited[nextRow][nextCol] == true ) continue;
        else {
            int sub = abs(map[row][col] - map[nextRow][nextCol]);
            if( sub >=L && sub <=R ) {
                DFS(visited, Union, sum, nextRow, nextCol);
            }
        }
    }

}

void solution() {

    bool flag = true;
    int day=0;

    while(flag == true) {   //one day
        makingUnion(flag);
        if(flag == true) { day++; }
    }

    std::cout << day;

}

int main() {
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Input();
    solution();


    return 0;
}

template <typename T>
void v2DInit(std::vector<std::vector<T> >&v, int row, int col, T val) {
    v.clear();
    std::vector<std::vector<T> >().swap(v);
    v.resize(row);
    for(int i=0; i<row; i++) {
        v[i].resize(col, val);
    }
}



void MovePopulation(std::vector<std::pair<int, int> >& Union, int& sum) {

    int uSize = Union.size();
    sum /= uSize;

    for(int i=0; i<uSize; i++) {
        int row = Union[i].first;
        int col = Union[i].second;
        map[row][col] = sum;
    }
}