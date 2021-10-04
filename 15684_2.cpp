//baekjoon 15684
//for all case: brute force
//DFS


//Check all situation from 0 to 3
//fcn Check(0), (1), (2), (3)
//#define MAX 4
//use queue and flag so that if min is changed, make q empty (no need to check more with same H)
//if still min == MAX, printf -1
//use int& min to check min
//use matrix[H][N]. if matrix[h][row] == 1, it means row-row+1 is connected at h

#include<iostream>
#include<queue>
#include<vector>
#define MAX 4

//fcns
template <typename T>
void v2DInit(std::vector<std::vector<T> >& v, int row, int col, T val);
void SituationCheck(int& min, int cnt, bool& flag, int nIdx);
inline void ArrivalCheck(int& min, bool& flag, int& cnt);
bool answer(int departure);


int N=0, M=0, H=0;
std::vector<std::vector<bool> >matrix;


int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //0. Enter Input
    std::cin >> N >> M >> H;

    v2DInit(matrix, N+1, H, false); //0 <= h <= H-1, 0 <= n <= N

    int htmp=0, ntmp=0;
    for(int i=0; i<M; i++) {
        std::cin >> htmp >> ntmp;
        matrix[ntmp][htmp-1] = true;
    }


    //1. use queue to check all situation
    int min=MAX;
    bool flag = false;
    SituationCheck(min, 0, flag, 1);


    if(min == MAX) {
        std::cout << -1;
    }
    else
        std::cout << min;


    return 0;
}

template <typename T>
void v2DInit(std::vector<std::vector<T> >& v, int row, int col, T val) {
    v.resize(row);
    for(int i=0; i<row; i++) {
        v[i].resize(col, val);
    }
}

void SituationCheck(int& min, int cnt, bool& flag, int nIdx) {

    if( flag == true || cnt >=4 ) return;
    ArrivalCheck(min, flag, cnt);
    //matrix check
    /*
    std::cout << std::endl << std::endl;
    for(int i=0; i<H; i++) {
        for(int j=0; j<=N; j++) {
            std::cout << matrix[j][i] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    */
    //
    if(flag == true) return;

    for(int n=nIdx; n<N; n++) {
        for(int h=0; h<H; h++) {
            if( matrix[n][h]==true ) continue;
            if( matrix[n-1][h]==true ) continue;   //if has Left, check Left
            if( matrix[n+1][h]==true ) continue;    //if has Right, check Right

            matrix[n][h] = true;
            SituationCheck(min, cnt+1, flag, n);
            matrix[n][h] = false;
        }
    }

}

inline void ArrivalCheck(int& min, bool& flag, int& cnt) {

    //int departure = 0;
    for(int departure=1; departure<=N; departure++) {
        if(answer(departure) != true) { //if departure does not go to same no.
            return;
        }
    }
    //if all depareture goes well
    flag = true;
    min = cnt;
}

bool answer(int departure) {

    int curPos = departure;
    for(int h=0; h<H; h++) {
        if(matrix[curPos][h] == true) curPos++;
        else if(matrix[curPos-1][h] == true) curPos--;
    }

    if(curPos == departure) return true;
    return false;
}