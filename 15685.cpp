//baekjoon 15685
//DragonCurve
//recursive
//ex.K curve: K-1 curve(a) + K-1 curve at end point of curve(a)
//방향을 보면 끝점 기준으로 시계방향 90도 이므로, curve0을 그려준 후에는 반시계로 90도 돌려줘야함
//

/*

    

*/
#include<iostream>
#include<vector>
#include<stack>
int N=0;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
enum {RIGHT, UP, LEFT, DOWN};   //d = d+1 하면 반시계 90도



//fcns
template <typename T>
void v2DInit(std::vector<std::vector<T> >& v, int row, int col, T val);
void VisitedPrint(std::vector<std::vector<int> >& visited);
void MakeCurve(std::vector<std::vector<int> >& visited, int& curX, int& curY, int& curD, int K);
void solution(std::vector<std::vector<int> >& visited, std::vector<std::vector<int> >& order, int& answer);
void CountSquare (std::vector<std::vector<int> >& visited, int& answer);
void RotateAdd(std::vector<std::vector<int> >& visited, std::vector<std::vector<int> >& visitedtmp, int& startX, int& startY, int& curX, int& curY);
inline void Rotate(int& x, int& y);


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N;
    std::vector<std::vector<int> > visited;
    v2DInit(visited, 101, 101, 0);  //[x][y]

    std::vector<std::vector<int> > order(N);    // order: x, y, direction, generation
    for(int i=0; i<N; i++) {
        int temp0=0, temp1=0, temp2=0, temp3=0;
        std::cin >> temp0 >> temp1 >> temp2 >> temp3;
        order[i].push_back(temp0);
        order[i].push_back(temp1);
        order[i].push_back(temp2);
        order[i].push_back(temp3);
    }
    int answer=0;
    solution(visited, order, answer);
    std::cout << answer;

    return 0;
}

template <typename T>
void v2DInit(std::vector<std::vector<T> >& v, int row, int col, T val) {
    v.resize(row);
    for(int i=0; i<row; i++)
        v[i].resize(col, val);
}

void VisitedPrint(std::vector<std::vector<int> >& visited) {
    for(int y=0; y<=10; y++) {
        for(int x=0; x<=10; x++) {
            std::cout << visited[x][y] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

void MakeCurve(std::vector<std::vector<int> >& visited, int& curX, int& curY, int& curD, int K) {

        if(K == 0) {
        int newX = curX+dx[curD], newY = curY+dy[curD];
        if(newX<0 || newY<0 || newX>100 || newY>100) return;
        else {
            visited[curX][curY] = 1;
            curX = newX;
            curY = newY;
            visited[curX][curY] = 1;
            //curD = (curD+1)%4;  //change direction  //여기서 바꾸지 말고 뒤에서 바꿀 것
            //curX, curY가 endpoint
            return;
        }
    }
    int startX=curX, startY=curY;
    std::vector<std::vector<int> > visitedtmp;
    v2DInit(visitedtmp, 101, 101, 0);
    visitedtmp[curX][curY] = 1;
    MakeCurve(visitedtmp, curX, curY, curD, K-1);
    RotateAdd(visited, visitedtmp, startX, startY, curX, curY);

}

void RotateAdd(std::vector<std::vector<int> >& visited, std::vector<std::vector<int> >& visitedtmp, int& startX, int& startY, int&curX, int& curY) {

    int endX=0, endY=0;
    for(int x=0; x<=100; x++) {
        for(int y=0; y<=100; y++) {
            if(visitedtmp[x][y] == 1) {
                visited[x][y] = 1;  //copy
                int tmpX=x-curX;
                int tmpY=y-curY;
                Rotate(tmpX, tmpY);
                tmpX+=curX; //add endpoint
                tmpY+=curY;
                if(tmpX>=0 && tmpX<=100 && tmpY>=0 && tmpY<=100){
                    visited[tmpX][tmpY] = 1;    //copy moved dot
                    if(x==startX && y==startY) {
                        endX=tmpX;      //change endpoint
                        endY=tmpY;
                    }
                }
                    //VisitedPrint(visited);
                    //std::cout << std::endl;
            }
        }
    }

    curX=endX;
    curY=endY;

    //다 하고 나서 endpoint check 필요. 왜냐면 다음 rotateAdd 시 endpoint를 기점으로 덧붙이기 때문에 endpoint를 찾는 작업이 필요하다
}

inline void Rotate(int& x, int& y) {
    //CCW: x, y -> -y, x
    //CW: x, y -> y, -x
    int tmp = x;
     //CCW
    //x = y;
    //y = -tmp;
    //CW
    x = -y;
    y = tmp;

}


void solution(std::vector<std::vector<int> >& visited, std::vector<std::vector<int> >& order, int& answer) {

    int x=0, y=0, d=0, k=0;
    for(int i=0; i<N; i++) {
        x = order[i][0];
        y = order[i][1];
        d = order[i][2];
        k = order[i][3];
        //int rotateFlag=0;
        MakeCurve(visited, x, y, d, k);
        //VisitedPrint(visited);
    }

    CountSquare(visited, answer);

}

void CountSquare (std::vector<std::vector<int> >& visited, int& answer) {

    for(int x=0; x<100; x++) {
        for(int y=0; y<100; y++) {
            if( visited[x][y] == 1 && visited[x][y+1] == 1 && visited[x+1][y] == 1 && visited[x+1][y+1] == 1 ) {
                answer++;
            }
        }
    }

}