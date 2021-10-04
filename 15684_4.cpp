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

//compared with ver3
//erase flag

//correct
//틀린 이유는 flag 사용 그 자체가 아니라 situationcheck 첫 조건문에서 if(flag == true || cnt >= 4) return; 으로 해버리면 dfs꼴로 만든 상황에서 min이 아닌 cnt여도 조건에만 부합하면
//바로 다른 case는 보지 않기 때문에 잘못된 최적화임.
//따라서 flag == true를 지워주어야 한다.
//결론은 flag는 최적화를 위해 만들어놓은 것인데, bfs꼴이 아니라 dfs 꼴로 만들어놓았으므로 cnt<=3인 case는 전부 다 확인해야 하고, 따라서 flag는 있을 이유가 없음.
//처음에 bfs꼴로 cnt==0이라 가정하고 확인, cnt==1이라 가정하고 확인, cnt==2라 가정하고 확인 이런 식으로 했으나
//이 경우 cnt=n -> cnt=n+1이 되면 cnt=0인 case*한개추가된케이스 라서 반복된 case를 다시 재방문해야 한다.
//따라서 cnt==3일 경우(최대일 경우) 전체를 다 훑어보는 것보다 더 많은 시간을 사용하게 되어 시간초과 문제가 발생
//따라서 그냥 한 바퀴 다 훑어보는 것이 더 평균적으로 빠름.
//혹은 정통 bfs로 해야 좋은데, 조합의 특성 상 어려움. 모든 케이스를 방문했는지 안 방문했는지 저장해둘 수가 없음
//따라서 brute force문제이며, dfs꼴로 만드는 것이 맞다.

//3번이 정답인 case고, 현재 이 4번 case는 시간 초과가 뜸.
//3번에서 if(flag == true) return;에 주석 달면 마찬가지로 시간 초과.
//즉, 이 if문이 뒤에 있음으로써 현재 flag를 true로 만든 cnt와 같은 값의 cnt case까지는 전부 체크해줌.
//하지만 그 이상의 진행은 막아줌으로써, 이미 min == 2 인데 cnt 3까지 더 체크해보는 상황을 막아줌.
//이 ver4에서는 if(min <= cnt) return; 을 달아주면 flag와 같은 역할을 함.

//fcns
template <typename T>
void v2DInit(std::vector<std::vector<T> >& v, int row, int col, T val);
void SituationCheck(int& min, int cnt, int hIdx);
bool ArrivalCheck(int& min, int& cnt);


int N=0, M=0, H=0, answer=0;
std::vector<std::vector<bool> >matrix;


int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //0. Enter Input
    std::cin >> N >> M >> H;

    v2DInit(matrix, N+1, H+1, false); //0 <= h <= H-1, 0 <= n <= N

    int htmp=0, ntmp=0;
    for(int i=0; i<M; i++) {
        std::cin >> htmp >> ntmp;
        matrix[ntmp][htmp] = true;
    }


    //1. use queue to check all situation
    int min=MAX;
    bool flag = false;
    SituationCheck(min, 0, 1);


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

void SituationCheck(int& min, int cnt, int hIdx) {

    if( cnt >=4 ) return;

    if (ArrivalCheck(min, cnt) == true) {
        min = (min < answer) ? min : answer;
        return;
    }
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
    if(min <= cnt) return;  //이 문장으로 시간 초과 해결

    for(int h=hIdx; h<=H; h++) {
        for(int n=1; n<N; n++) {
            if( matrix[n][h]==true ) continue;
            if( matrix[n-1][h]==true ) continue;   //if has Left, check Left
            if( matrix[n+1][h]==true ) continue;    //if has Right, check Right

            matrix[n][h] = true;
            SituationCheck(min, cnt+1, h);
            matrix[n][h] = false;
        }
    }
}

bool ArrivalCheck(int& min, int& cnt) {

    //int departure = 0;
    for(int departure=1; departure<=N; departure++) {
        int curPos = departure;
        for(int j=1; j<=H; j++) {
            if(matrix[curPos][j] == true) curPos++;
            else if(matrix[curPos-1][j] == true) curPos--;
        }

        if(curPos != departure) return false;
    }
    //if all depareture goes well
    answer = cnt;
    return true;
}
