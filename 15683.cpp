//baekjoon 15683
//recursive

//1. switch를 이용해 어느 모델인지 체크
//2. 1번: 4case, 2번: 2case, 3: 4case, 4:4case, 5:1case
//3. 각각의 경우에 대해서 for(0<=i<case_no)의 상황에 맞춰 direction 바꿔가며 다음 거를 recursive로 call


#include<iostream>
#include<vector>

using namespace std;

int N=0, M=0;
enum {EAST, SOUTH, WEST, NORTH};
int dRow[] = {0, 1, 0, -1};
int dCol[] = {1, 0, -1, 0};

//fcns
template <typename T>
void v2DInit(vector<vector<T> >& map, int row, int col, T val);
void SelectCCTV(vector<vector<int> > map, vector<vector<int> >& cctv, int cnt, int& min);
void AddSurveillance1(vector<vector<int> > map, vector<vector<int> >& cctv, int cnt, int& min, int direction);
void AddSurveillance2(vector<vector<int> > map, vector<vector<int> >& cctv, int cnt, int& min, int direction);
void AddSurveillance3(vector<vector<int> > map, vector<vector<int> >& cctv, int cnt, int& min, int direction);
void AddSurveillance4(vector<vector<int> > map, vector<vector<int> >& cctv, int cnt, int& min, int direction);
void AddSurveillance5(vector<vector<int> > map, vector<vector<int> >& cctv, int cnt, int& min);
void findMin(vector<vector<int> >&map, int& min);

template <typename T>
void v2DInit(vector<vector<T> >& map, int row, int col, T val) {
    map.resize(row);
    for(int i=0; i<row; i++)
        map[i].resize(col, val);
}

void SelectCCTV(vector<vector<int> > map, vector<vector<int> >& cctv, int cnt, int& min) {

    if(cnt == cctv.size()) {
        findMin(map, min);
        return;
    }

    //AddSurveillance(map, cctv, cnt, min,)
    int curType = cctv[cnt][0];

    switch(curType) {
        case(1):    //4 cases
            for(int i=0; i<4; i++) {
                AddSurveillance1(map, cctv, cnt, min, i);
            }
            break;
        case(2):    //2 cases
            for(int i=0; i<2; i++) {
                AddSurveillance2(map, cctv, cnt, min, i);
            }
            break;
        case(3):
            for(int i=0; i<4; i++) {
                AddSurveillance3(map, cctv, cnt, min, i);
            }
            break;
        case(4):
            for(int i=0; i<4; i++) {
                AddSurveillance4(map, cctv, cnt, min, i);
            }
            break;
        case(5):
                AddSurveillance5(map, cctv, cnt, min);
            break;
    }

}

void AddSurveillance1(vector<vector<int> > map, vector<vector<int> >& cctv, int cnt, int& min, int direction) {
    //direction: EAST=0, SOUTH, WEST, NORTH
    //add direction points until meet wall or meet the end
    int curRow = cctv[cnt][1], curCol = cctv[cnt][2];
    while(1) {
        curRow += dRow[direction];
        curCol += dCol[direction];
        if(curRow<0 || curRow>=N || curCol<0 || curCol>=M)
            break;
        else if(map[curRow][curCol] == 6)
            break;
        else if(map[curRow][curCol] == 0) {
            map[curRow][curCol] = 9;
        }
    }

    SelectCCTV(map, cctv, cnt+1, min);
}

void AddSurveillance2(vector<vector<int> > map, vector<vector<int> >& cctv, int cnt, int& min, int direction) {
    //direction: EAST=0, SOUTH, WEST, NORTH
    //add direction points until meet wall or meet the end
    int curRow = cctv[cnt][1], curCol = cctv[cnt][2];

    while(1) {
        curRow += dRow[direction];
        curCol += dCol[direction];
        if(curRow<0 || curRow>=N || curCol<0 || curCol>=M)
            break;
        else if(map[curRow][curCol] == 6)
            break;
        else if(map[curRow][curCol] == 0) {
            map[curRow][curCol] = 9;
        }
    }

    curRow = cctv[cnt][1], curCol = cctv[cnt][2];
    direction += 2;
    while(1) {
        curRow += dRow[direction];
        curCol += dCol[direction];
        if(curRow<0 || curRow>=N || curCol<0 || curCol>=M)
            break;
        else if(map[curRow][curCol] == 6)
            break;
        else if(map[curRow][curCol] == 0) {
            map[curRow][curCol] = 9;
        }
    }

    SelectCCTV(map, cctv, cnt+1, min);
}

void AddSurveillance3(vector<vector<int> > map, vector<vector<int> >& cctv, int cnt, int& min, int direction) {
    //direction: EAST=0, SOUTH, WEST, NORTH
    //add direction points until meet wall or meet the end
    int curRow = cctv[cnt][1], curCol = cctv[cnt][2];
    while(1) {
        curRow += dRow[direction];
        curCol += dCol[direction];
        if(curRow<0 || curRow>=N || curCol<0 || curCol>=M)
            break;
        else if(map[curRow][curCol] == 6)
            break;
        else if(map[curRow][curCol] == 0) {
            map[curRow][curCol] = 9;
        }
    }

    curRow = cctv[cnt][1], curCol = cctv[cnt][2];
    direction = (direction+1)%4;
    while(1) {
        curRow += dRow[direction];
        curCol += dCol[direction];
        if(curRow<0 || curRow>=N || curCol<0 || curCol>=M)
            break;
        else if(map[curRow][curCol] == 6)
            break;
        else if(map[curRow][curCol] == 0) {
            map[curRow][curCol] = 9;
        }
    }

    SelectCCTV(map, cctv, cnt+1, min);
}

void AddSurveillance4(vector<vector<int> > map, vector<vector<int> >& cctv, int cnt, int& min, int direction) {
    //direction: EAST=0, SOUTH, WEST, NORTH
    //add direction points until meet wall or meet the end
    int curRow = cctv[cnt][1], curCol = cctv[cnt][2];
    while(1) {
        curRow += dRow[direction];
        curCol += dCol[direction];
        if(curRow<0 || curRow>=N || curCol<0 || curCol>=M)
            break;
        else if(map[curRow][curCol] == 6)
            break;
        else if(map[curRow][curCol] == 0) {
            map[curRow][curCol] = 9;
        }
    }

    curRow = cctv[cnt][1], curCol = cctv[cnt][2];
    direction = (direction+1)%4;
    while(1) {
        curRow += dRow[direction];
        curCol += dCol[direction];
        if(curRow<0 || curRow>=N || curCol<0 || curCol>=M)
            break;
        else if(map[curRow][curCol] == 6)
            break;
        else if(map[curRow][curCol] == 0) {
            map[curRow][curCol] = 9;
        }
    }

    curRow = cctv[cnt][1], curCol = cctv[cnt][2];
    direction = (direction+1)%4;
    while(1) {
        curRow += dRow[direction];
        curCol += dCol[direction];
        if(curRow<0 || curRow>=N || curCol<0 || curCol>=M)
            break;
        else if(map[curRow][curCol] == 6)
            break;
        else if(map[curRow][curCol] == 0) {
            map[curRow][curCol] = 9;
        }
    }

    SelectCCTV(map, cctv, cnt+1, min);
}


void AddSurveillance5(vector<vector<int> > map, vector<vector<int> >& cctv, int cnt, int& min) {
    //direction: EAST=0, SOUTH, WEST, NORTH
    //add direction points until meet wall or meet the end
    int curRow = cctv[cnt][1], curCol = cctv[cnt][2];
    for(int direction=0; direction<4; direction++) {
        curRow = cctv[cnt][1], curCol = cctv[cnt][2];
        while(1) {
            curRow += dRow[direction];
            curCol += dCol[direction];
            if(curRow<0 || curRow>=N || curCol<0 || curCol>=M)
                break;
            else if(map[curRow][curCol] == 6)
                break;
            else if(map[curRow][curCol] == 0) {
                map[curRow][curCol] = 9;
            }
        }    
    }
    SelectCCTV(map, cctv, cnt+1, min);
}

void findMin(vector<vector<int> >&map, int& min) {
    int zeroCnt = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(map[i][j] == 0) 
                zeroCnt++;
        }
    }

    min = (min < zeroCnt) ? min : zeroCnt;
}



int main() {

    cin >> N >> M;
    vector<vector<int > > map;
    vector<vector<int> >cctv;

    v2DInit(map, N, M, 0);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            if(map[i][j] >=1 && map[i][j] <=5) {
                cctv.push_back({map[i][j], i, j});  // { cctv_type, row, col }
            }
            //else if(map[i][j] == 0) zeroCnt++;
        }
    }
    
    //map check
    /*
    cout << endl;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cout << map[i][j] << ' ';
        }
        cout <<endl;
    }
    cout << endl;
    */
    //
    int min = N*M;
    SelectCCTV(map, cctv, 0, min);
    cout << min;

    return 0;
}