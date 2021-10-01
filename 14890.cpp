//baekjoon 14890
//simulation

//bool possibleFlag 를 만들어서 현재 높이가 L번 지속될 경우
//true로 바꾸어준다.
//이후 하나 현재 높이와 다른 곳을 만나면 +-1인지 체크
//+-1이 아니면 return/break
//+-1이면 possibleFlag 체크, false일 경우 return/break
//possible일 경우 flag = false로 바꿔주고 진행

#include<iostream>
#include<vector>

using namespace std;

int N=0, L=0;
enum {VERTICAL, HORIZONTAL};

int absSub(int a, int b) {

    if(a>b) return a-b;
    else return b-a;

}

void v2Init(vector<vector<int> >& map, int row, int col, int val) {
    map.resize(row);
    for(int i=0; i<row; i++) {
        map[i].resize(col, val);
    }
}

bool slide(vector<vector<int> >& map, int& cIdx, int& beforeVal) {
    //현재 값이 바뀐 위치가 cIdx
    //바뀌기 전 값이 beforeVal
    //if 값이 바뀐 위치인 cIdx+L-1이 >=N 이면 false
    //그렇지 않다면, cIdx+L-1까지 값이 일정해야함
    //일정할 경우 return true, beforeVal은 cIdx+L-1값이 됨
}

bool WellMadeRoad(vector<vector<int> >& map, int idx, int direction) {
    int *row, *col;
    int cIdx=0;
    if(direction == VERTICAL) {
        row = &cIdx;
        col = &idx;
    }
    else{
        row = &idx;
        col = &cIdx;
    }

    int beforeVal = map[*row][*col];
    int cnt=1;
    //increasing idx
    while(1) {
        
        cIdx++;
        if(cIdx == N) return true;
        while(beforeVal == map[*row][*col]) {
            if(cIdx == (N-1)) return true;
            cIdx++;
            cnt++;
        }

        if(absSub(beforeVal, map[*row][*col]) > 1) return false;
        else {
            if(beforeVal > map[*row][*col]) {//내리막
                //현재 값이 바뀐 위치가 cIdx
                //바뀌기 전 값이 beforeVal
                //if 값이 바뀐 위치인 cIdx+L-1이 >=N 이면 false
                if(cIdx+L-1 >= N) return false;
                //그렇지 않다면, cIdx+L-1까지 값이 일정해야함
                int tmp = map[*row][*col];
                for(int i=0; i<(L-1); i++) {
                    cIdx++;
                    if(tmp != map[*row][*col]) return false;
                }
                //일정할 경우 return true, cIdx는 내리막을 다 설치한 다음 칸을 가르키게 되고 beforeVal은 내리막 설치 이후 칸의 값을 갖게 됨. (처음 시작처럼)
                //내리막을 다 설치한 다음 칸이 없으면 return true
                if(cIdx == (N-1)) return true;
                //cIdx++;
                beforeVal = map[*row][*col];
                cnt=0;
            }
            else {  //오르막
                if(cnt < L) return false;
                beforeVal = map[*row][*col];
                cnt=1;
            }
            continue;
        }
        return false;
    }
}

int main() {

    cin >> N >> L;
    vector<vector<int> > map;
    v2Init(map, N, N, 0);

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }

    int totalRoad=0;
    for(int col=0; col<N; col++) {
        if(WellMadeRoad(map, col, VERTICAL) == true)
            totalRoad++;
    }

    for(int row=0; row<N; row++) {
        if(WellMadeRoad(map, row, HORIZONTAL) == true)
            totalRoad++;
    }

    //map check
    /*
    cout << '\n';
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    */
   cout << totalRoad;


    return 0;
}