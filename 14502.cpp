//baekjoon 14502
//DFS

//fcns
//1. BuildWall -> map의 모든 0인 곳을 vector에 넣어 놓고, 모든 케이스에 대해 벽을 세워본다
/*
for(int i=0; i<v.size()-2; i++) {   //0<=i<=v.size()-3      //O(N^3)
    v[i] = 1;
    for(int j=i+1; j<v.size()-1; j++) { // i+1<=j<=v.size()-2
        v[j] = 1;
        for(int k=j+1; k<v.size(); k++) {// j+1<=k<=v.size()-1
            v[k] = 1;
            //Find max
            v[k] = 0;
        }
        v[j] = 0;
    }
    v[i] = 0;
}
*/

//2. use DFS to spread virus
//벽을 세운 상황에서 바이러스를 유포
//3. check 0 is left
    //if left, max와 0 남은 수를 비교해서 최댓값만 남기기

//4. main에서 max를 출력

#include<iostream>
#include<vector>
#define TRUE        1
#define FALSE       0
enum {EMPTY, WALL, VIRUS};

int N=0, M=0;
int dcol[] = {1, 0, -1, 0}; //RDLU
int drow[] = {0, 1, 0, -1};


//fcns
void vector2DInit(std::vector<std::vector<int> >& visited, int row, int col) {
    visited.resize(row);
    for(int i=0; i<row; i++) {
        visited[i].resize(col, 0);
    }
}

void findZero(std::vector<std::vector<int> >& map, std::vector<std::pair<int, int> >& whereIsZero) {
    for(int row=0; row<N; row++) {
        for(int col=0; col<M; col++) {
            if(map[row][col] == 0) whereIsZero.push_back({row, col});
        }
    }
}


void SpreadVirus(std::vector<std::vector<int> >& map, std::vector<std::vector<int> >& visited, int& cnt, int row, int col){    //DFS 

    if(visited[row][col] == TRUE) return;
    //else if(row<0 || row >=N || col<0 || col>=M) return;
    visited[row][col] = TRUE;

    for(int idx=0; idx<4; idx++) {
        if(row+drow[idx]<0 || row+drow[idx]>=N || col+dcol[idx]<0 || col+dcol[idx]>=M)
            continue;
        if(map[row+drow[idx]][col+dcol[idx]] == 0) {    //RDLU
            cnt++;  //cnt++ when 0 -> 2
            map[row+drow[idx]][col+dcol[idx]] = 2;
            //visited[row+drow[idx]][col+dcol[idx]] = TRUE;
            SpreadVirus(map, visited, cnt, row+drow[idx], col+dcol[idx]);
        }
    }



    //


}


void findMax(std::vector<std::vector<int> >& map, std::vector<std::pair<int, int> >& whereIsZero, int& max) {

    int cnt = 0;
    std::vector<std::vector<int> >maptmp0, maptmp1, maptmp2;
    maptmp0.assign(map.begin(), map.end()); //original map
    for(int i=0; i<whereIsZero.size()-2; i++) {   //0<=i<=v.size()-3      //O(N^3)

        map.assign(maptmp0.begin(), maptmp0.end());
        map[whereIsZero[i].first][whereIsZero[i].second] = 1;

        maptmp1.assign(map.begin(), map.end()); //after building first wall
        for(int j=i+1; j<whereIsZero.size()-1; j++) { // i+1<=j<=v.size()-2

            map.assign(maptmp1.begin(), maptmp1.end());
            map[whereIsZero[j].first][whereIsZero[j].second] = 1;

            maptmp2.assign(map.begin(), map.end()); //after building second wall
            for(int k=j+1; k<whereIsZero.size(); k++) {// j+1<=k<=v.size()-1    //build three wall

                map.assign(maptmp2.begin(), maptmp2.end());   //reset map
                map[whereIsZero[k].first][whereIsZero[k].second] = 1;   //build three wall
                cnt=0;
                //Find max
                std::vector<std::vector<int> > visited;
                vector2DInit(visited, N, M);
                for(int row=0; row<N; row++) {
                    for(int col=0; col<M; col++) {
                        if(map[row][col] == 2) {
                            SpreadVirus(map, visited, cnt, row, col);
                            //mapcheck
                            /*
                            std::cout << "\n\n";
                            for(int i=0; i<N; i++) {
                                for(int j=0; j<M; j++) {
                                    std::cout << map[i][j] << ' ';
                                }
                                std::cout << std::endl;
                            }
                            */
                            ////////
                        }
                    }
                }
                int ZeroNo = whereIsZero.size() - cnt - 3;  //total zero - added 2 - three walls
                max = (max > ZeroNo) ? max:ZeroNo;
                /*
                std::cout << "\n\n";
                //wall check
                std::cout << '{' << whereIsZero[i].first <<',' <<  whereIsZero[i].second <<'}' << std::endl;
                std::cout << '{' << whereIsZero[j].first <<',' <<  whereIsZero[j].second <<'}' << std::endl;
                std::cout << '{' << whereIsZero[k].first <<',' <<  whereIsZero[k].second <<'}' << std::endl;
                //mapcheck
                for(int i=0; i<N; i++) {
                    for(int j=0; j<M; j++) {
                        std::cout << map[i][j] << ' ';
                    }
                    std::cout << std::endl;
                }
                
                //max check
                std::cout << max <<std::endl;
                */
            }
        }
    }

}


int main() {
    
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;
    std::vector<std::vector<int> > map;
    vector2DInit(map, N, M);

    //0. Enter map
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
    */
    std::vector<std::pair<int, int> > whereIsZero;  // M*row+col;

    findZero(map, whereIsZero);

    //vector check
    /*
    std::cout << "\n\n";
    for(int i=0; i<whereIsZero.size(); i++) {
        std::cout << whereIsZero[i] << ' ';
    }
    std::cout << '\n';
    */
    int max=0;
    findMax(map, whereIsZero, max);
    std::cout << max;



    return 0;
}