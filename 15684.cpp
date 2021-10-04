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

inline void SituationCheck(std::vector<bool>& matrix, int& min, int& cnt, int curCnt, bool& flag, int idx);
inline void ArrivalCheck(std::vector<bool>& matrix, int& min, bool& flag, int& cnt);
bool answer(std::vector<bool>& matrix, int departure);

int N=0, M=0, H=0;

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //0. Enter Input
    std::cin >> N >> M >> H;

    std::vector<bool> matrix(H*(N-1), false); // matrix[H*n+h] == n-n+1 is connected at h

    int htmp=0, ntmp=0;
    for(int i=0; i<M; i++) {
        std::cin >> htmp >> ntmp;
        matrix[H*(ntmp-1)+htmp-1] = true;
    }


    //1. use queue to check all situation
    int cnt=0, min=MAX;
    //int MaxCnt = (M<3) ? M:3;
    while(cnt<=3) {
        bool flag = false;
        SituationCheck(matrix, min, cnt, 0, flag, 0);
        if(flag == true) break;
        cnt++;
    }

    if(min == MAX) {
        std::cout << -1;
    }
    else
        std::cout << min;


    return 0;
}


inline void SituationCheck(std::vector<bool>& matrix, int& min, int& cnt, int curCnt, bool& flag, int idx) {

    if( flag == true ) return;
    else if( curCnt == cnt ) {
        ArrivalCheck(matrix, min, flag, cnt);
        return;
    }

    for(int i=idx; i<H*(N-1); i++) {
        if(matrix[i] == true) continue;
        else {
            if(i-H >= 0) {  //if has Left, check Left
                if(matrix[i-H] == true) continue;
            }
            if( (i+H) <= ((N-1)*H-1) ) {    //if has Right, check Right
                if(matrix[i+H] == true) continue;
            }
            matrix[i] = true;
            SituationCheck(matrix, min, cnt, curCnt+1, flag, idx);
        }
        matrix[i] = false;
    }
}

inline void ArrivalCheck(std::vector<bool>& matrix, int& min, bool& flag, int& cnt) {

    //int departure = 0;
    for(int departure=0; departure<N; departure++) {
        if(answer(matrix, departure) != true) { //if departure does not go to same no.
            return;
        }
    }
    //if all depareture goes well
    flag = true;
    min = cnt;
}

bool answer(std::vector<bool>& matrix, int departure) {

    int curPos = departure;
    for(int h=0; h<H; h++) {
        if(curPos == 0) {
            if(matrix[H*curPos+h] == true)
                curPos++;   //move right

            continue;
        }
        else if(curPos == (N-1)) {
            if(matrix[H*(curPos-1)+h] == true)
                curPos--;   //move left
            
            continue;
        }
        else {
            if(matrix[H*curPos+h] == true) { curPos++; }  //move Right
            else if(matrix[H*(curPos-1)+h] == true) { curPos--; }  //move Left
        }
    }

    if(curPos == departure) return true;
    return false;
}