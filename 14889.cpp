//baekjoon 14889

#include<iostream>
#include<vector>

//1. 두 팀으로 나눌 수 있는 모든 케이스를 조사
//2. 각 상황에 대해 각 팀의 능력치 합 구한 후 차이를 min과 비교해 min에 저장

using namespace std;

int N=0;

void v2Init(vector<vector <int> >& stat, int row, int col, int val) {
    stat.resize(row);
    for(int i=0; i<row; i++)
        stat[i].resize(col, val);
}

void findMin(std::vector<vector<int> >& stat, vector<bool>& registered, int matSize, int &min)
{
    vector<int> teamA, teamB;
    int statA=0, statB=0;

    for(int i=0; i<matSize; i++) {
        if(registered[i] == false)
            teamA.push_back(i);
        else
            teamB.push_back(i);
    }

    for(int i=0; i<teamA.size(); i++) {
        for(int j=i+1; j<teamA.size(); j++) {
            statA += stat[teamA[i]][teamA[j]];
            statA += stat[teamA[j]][teamA[i]];
        }
    }

    for(int i=0; i<teamB.size(); i++) {
        for(int j=i+1; j<teamB.size(); j++) {
            statB += stat[teamB[i]][teamB[j]];
            statB += stat[teamB[j]][teamB[i]];
        }
    }

    int statSub = (statA > statB) ? (statA-statB) : (statB-statA);
    min = (min < statSub) ? min : statSub;
}

void TeamMaking(std::vector<vector<int> >& stat, vector<bool> registered, int matSize, int idx, int cnt, int& min) {
    
    if(cnt == N/2) {
        findMin(stat, registered, matSize, min);
        return;
    }

    for(int i=(idx+1); i<matSize; i++) {
        if(registered[i] == false) {
            registered[i] = true;
            TeamMaking(stat, registered, N, i, cnt+1, min);
            registered[i] = false;
        }
    }

}

int main() {

    cin >> N;
    vector<vector<int> >stat;
    v2Init(stat, N, N, 0);

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> stat[i][j];
        }
    }

    //stat check
    /*
    cout << endl;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << stat[i][j];
        }
        cout << endl;
    }
    cout << endl;
    */
    //
    int min=100*400;
    vector<bool> registered(N, false);
    TeamMaking(stat, registered, N, 0, 0, min);

    cout << min;

    return 0;
}