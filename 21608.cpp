//baekjoon 21608
//shark elementary school
//simulation

//condition1
//condition2
//condition3



#include<iostream>
#include<vector>

int N=0;
std::vector<std::vector<int> > Student; //v students like
std::vector<std::vector<int> > Map; //seat
std::vector<int> SeatOrder;
int drow[] = {1, 0, -1, 0};
int dcol[] = {0, -1, 0, 1};


template <typename T>
void v2DInit(std::vector<std::vector<T> >& v, int row, int col, T val);
void Input();
void Solution();
void DecideSeat();
int CntSatisfaction();
int CntEmptyNear(int row, int col);
int CntLikeNear(std::vector<int>& hero, int row, int col);

bool Condition1(std::vector<std::pair<int, int> >& SeatCandidate, int& hero);
bool Condition2(std::vector<std::pair<int, int> >& SeatCandidate, int& hero);
void Condition3(std::vector<std::pair<int, int> >& SeatCandidate, int& hero);


template <typename T>
void v2DInit(std::vector<std::vector<T> >& v, int row, int col, T val) {
    
    v.clear();
    std::vector<std::vector<T> >().swap(v);

    v.resize(row);
    for(int i=0; i<row; i++) {
        v[i].resize(col, val);
    }
}


int CntEmptyNear(int row, int col) {

    int cnt=0;
    for(int i=0; i<4; i++) {
        int newRow = row+drow[i];
        int newCol = col+dcol[i];
        if( newRow<0 || newRow>=N || newCol<0 || newCol>=N ) continue;
        else {
            if(Map[newRow][newCol] == 0) cnt++;
        }
    }

    return cnt;
}

int CntLikeNear(std::vector<int>& hero, int row, int col) {

    int cnt=0;
    for(int i=0; i<4; i++) {
        int newRow = row+drow[i];
        int newCol = col+dcol[i];
        if( newRow<0 || newRow>=N || newCol<0 || newCol>=N ) continue;
        else if ( Map[newRow][newCol] == hero[0] || Map[newRow][newCol] == hero[1]
            || Map[newRow][newCol] == hero[2] || Map[newRow][newCol] == hero[3] ) { cnt++; }
    }

    return cnt;
}

bool Condition1(std::vector<std::pair<int, int> >& SeatCandidate, int& hero) {

    std::vector<std::vector< std::pair<int, int> > >LikeNear(5);   //LikeNear[x] : seats which has x LikeNear
    int max=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(Map[i][j] != 0) continue;
            int LikeSeatCnt = CntLikeNear(Student[hero], i, j);
            if(max < LikeSeatCnt) max=LikeSeatCnt;
            LikeNear[LikeSeatCnt].push_back({i, j});
        }
    }

    if( LikeNear[max].size() == 1 ) {
        int row=LikeNear[max][0].first;
        int col=LikeNear[max][0].second;
        Map[row][col] = hero;
        return true;    //only 1 candidate -> completely take a seat
    }
    else {
        SeatCandidate.assign( LikeNear[max].begin(), LikeNear[max].end() );   //fail to take a seat
        return false;   //forward SeatCandidate and return false
    }

}

bool Condition2(std::vector<std::pair<int, int> >& SeatCandidate, int& hero) {

    std::vector<std::vector< std::pair<int, int> > >EmptyNear(5);   //EmptyNear[x] : seats which has x emptynear
    int max=0;
    int SeatCandidateSize = SeatCandidate.size();
    for(int i=0; i<SeatCandidateSize; i++) {

        int SeatRow = SeatCandidate[i].first;
        int SeatCol = SeatCandidate[i].second;
        int EmptySeatCnt = CntEmptyNear(SeatRow, SeatCol);

        if(max < EmptySeatCnt) max=EmptySeatCnt;
        EmptyNear[EmptySeatCnt].push_back({SeatRow, SeatCol});

    }

    if( EmptyNear[max].size() == 1 ) {
        int row=EmptyNear[max][0].first;
        int col=EmptyNear[max][0].second;
        Map[row][col] = hero;
        return true;    //only 1 candidate -> completely take a seat
    }
    else {
        SeatCandidate.assign( EmptyNear[max].begin(), EmptyNear[max].end() );   //fail to take a seat
        return false;   //forward SeatCandidate and return false
    }
}

void Condition3(std::vector<std::pair<int, int> >& SeatCandidate, int& hero) {

    int SeatCandidateSize = SeatCandidate.size();
    int rowMin=(N-1);

    //row condition;
    std::vector<std::vector<int> > rowV(N); //rowV[x][idx] : idx is seatcandidate idx, and x is row no.
    for(int i=0; i<SeatCandidateSize; i++) {
        int CandidateRow = SeatCandidate[i].first;
        if(CandidateRow <= rowMin) {
            rowMin = CandidateRow;
            rowV[rowMin].push_back(i);
        }
    }

    if(rowV[rowMin].size() == 1) {
        int idx = rowV[rowMin][0];
        int realRow = SeatCandidate[idx].first;
        int realCol = SeatCandidate[idx].second;
        Map[realRow][realCol] = hero;
        return;
    }

    //col condition;
    std::vector<std::vector<int> > colV(N); //colV[x][idx] : idx is seatcandidate idx, and x is row no.
    int rowVSize = rowV[rowMin].size();
    int colMin = (N-1);
    int colIdx=0;

    for(int i=0; i<rowVSize; i++) {
        int candidateIdx = rowV[rowMin][i];
        int candidateCol = SeatCandidate[candidateIdx].second;
        if(candidateCol <= colMin) {
            colIdx = candidateIdx;
        }
    }

    int finalRow = SeatCandidate[colIdx].first;
    int finalCol = SeatCandidate[colIdx].second;
    Map[finalRow][finalCol] = hero;

}

//std::vector<std::vector<int> > Student; //v students like
int CntSatisfaction() {
    
    int cnt=0;
    int satisfaction=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {    //for all points


            //////

            cnt=0;
            int hero = Map[i][j];
            for(int k=0; k<4; k++) {
                int newRow = i+drow[k];
                int newCol = j+dcol[k];
                if( newRow<0 || newRow>=N || newCol<0 || newCol>=N ) continue;
                else if( Map[newRow][newCol] == Student[hero][0] ||  Map[newRow][newCol] == Student[hero][1]
                        || Map[newRow][newCol] == Student[hero][2] ||  Map[newRow][newCol] == Student[hero][3] ){
                            cnt++;
                }
            }
            switch(cnt) {
                case(1):
                    satisfaction+=1;
                break;
                case(2):
                    satisfaction+=10;
                break;
                case(3):
                    satisfaction+=100;
                break;
                case(4):
                    satisfaction+=1000;
                break;
                default:
                break;
            }

            //////


        }
    }

    return satisfaction;
}


void DecideSeat() {

    std::vector<std::pair<int, int> > SeatCandidate;
    for(int i=0; i<N*N; i++) {    //for all students
        SeatCandidate.clear();
        std::vector<std::pair<int, int> >().swap(SeatCandidate);    //reset candidate
        if ( Condition1( SeatCandidate, SeatOrder[i] ) == true ) continue;
        else if( Condition2( SeatCandidate, SeatOrder[i] ) == true ) continue;
        else Condition3( SeatCandidate, SeatOrder[i] );

    }

}



////////////////////////////////////////

int main() {

    Input();
    Solution();

/*
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            std::cout << Map[i][j] << ' ';
        }
        std::cout << std::endl;
    }
*/

    return 0;
}

void Input() {

    std::cin >> N;
    v2DInit(Student, N*N+1, 4, 0);
    for(int i=0; i<N*N; i++) {
        int tmp=0;
        std::cin >> tmp;
        SeatOrder.push_back(tmp);
        for(int j=0; j<4; j++) {
            std::cin >> Student[tmp][j];  //Student[tmp] like student[tmp][0], [1], ...
        }
    }

}

void Solution() {

    v2DInit(Map, N, N, 0);  //0 == EMPTY
    DecideSeat();
    std::cout << CntSatisfaction();

}

