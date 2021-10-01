//baekjoon 14503
//210927 17:17 start
//BFS

//cycle: clean ->


//search



#include<iostream>
#include<vector>

//1. 왼쪽이 비었으면 왼쪽으로 회전 후 한 칸 전진, 청소 -> 다시 바라보는 방향의 왼쪽부터 체크
//2. 왼쪽이 안 비었으면 왼쪽으로 회전 후 새로운 방향에서 다시 1
//3. 그렇게 4번 돌았는데 다 청소가 되어 있는 경우 -> 다시 처음 방향으로 돌아왔을 것 -> 후진 후 다시 1
//

int N=0, M=0;
int dCol[] = {0, 1, 0, -1}; //LDRU
int dRow[] = {-1, 0, 1, 0}; //turn left == d

enum {NORTH, EAST, SOUTH, WEST};
//need to do direction += 3;

using namespace std;

//fcns
inline void v2DInit(std::vector<std::vector<int> >& v2, int rowSize, int colSize, int val) {

    v2.resize(rowSize);
    for(int i=0; i<rowSize; i++)
        v2[i].resize(colSize, val);

}

inline void clean(std::vector<std::vector<int> >& map, int row, int col) {
    map[row][col] = 2;
}

inline void turnLeft(int& d) {
    d = (d+3)%4;   //0123: LDRU
}

bool IsLeftEmpty(std::vector<std::vector<int > >& map, int cRow, int cCol, int d) {
    turnLeft(d);
    int LRow=cRow+dRow[d];
    int LCol=cCol+dCol[d];
    if( map[LRow][LCol] == 0 )
        return true;
    else
        return false;
}

void robotMotion(std::vector<std::vector<int > >& map, int cRow, int cCol, int d, int& cleanedBlock) {

    int cnt=0;
    while(1) {
        
        //1. clean current position
        if(map[cRow][cCol] == 0){
            clean(map, cRow, cCol);
            cleanedBlock++;
            //map check
            /*
            std::cout << "\n\n";
            for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) {
                    std::cout << map[i][j] << ' ';
                }
                std::cout << '\n';
            }
            std::cout << std::endl;
            */
        }

        //2.

        //2-a. 왼쪽이 비었으면 왼쪽으로 회전 후 한 칸 전진, 1로 복귀
        if(IsLeftEmpty(map, cRow, cCol, d) == true) {
            turnLeft(d);    //direction changed
            cRow += dRow[d];    //move on
            cCol += dCol[d];
            cnt=0;
            continue;   //go to 1
        }
        else if(cnt != 4){//2-b. 왼쪽이 안 비었으면 왼쪽으로 회전 후 새로운 방향에서 다시 1
            cnt++;
            turnLeft(d);    //0:NORTH, 1:EAST, 2:SOUTH, 3:WEST
            continue;
        }
        else {  //cnt == 4, 즉 네 방향 다 봤는데 갈 곳이 없으면 (2-c)
            cRow -= dRow[d];
            cCol -= dCol[d];
            cnt = 0;
            if( map[cRow][cCol] != 1 ){
                continue;
            }
            else return;
        }


        //3. 그렇게 4번 돌았는데 다 청소가 되어 있는 경우 -> 다시 처음 방향으로 돌아왔을 것 -> 후진 후 다시 1
        //

    }


}

int main()
{


    std::cin >> N >> M;
    int cRow=0, cCol=0, d=0;
    std::cin >> cRow >> cCol >> d;

    std::vector<std::vector<int> > map;
    v2DInit(map, N, M, 0);

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            std::cin >> map[i][j];
        }
    }

    //map check
    /*
    std::cout << "\n\n";
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            std::cout << map[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
    */

    int cleanedBlock=0;
    robotMotion(map, cRow, cCol, d, cleanedBlock);

    std::cout << cleanedBlock;




    return 0;
}