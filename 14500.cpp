//baekjoon 14500
//Need to check all cases -> DFS

//MODEL1
// ㅁㅁㅁㅁ : 2 cases // 2 rotate 

//MODEL2
// ㅁㅁ
// ㅁㅁ : one case

//MODEL3
// ㅁ
// ㅁ
// ㅁ
// ㅁ ㅁ : 8 cases // 4 rotate * 2 fold

//MODEL4
// ㅁ
// ㅁ ㅁ
//    ㅁ : 4 cases // 2 rotate * 2 fold

//MODEL5
// ㅁ ㅁ ㅁ
//    ㅁ     : 4 cases // 4 rotate


#include<iostream>
#include<vector>

int N=0, M=0;

enum {MODEL1, MODEL2, MODEL3, MODEL4, MODEL5};

//fcns
//1. check it is possible -> main point
//2. if poosible, check sum and compare with max
//3. if max < sum, change
//4. move position
void MODEL1Check(std::vector<std::vector<int> >& map, int row, int col, int& max);
void MODEL2Check(std::vector<std::vector<int> >& map, int row, int col, int& max);
void MODEL3Check(std::vector<std::vector<int> >& map, int row, int col, int& max);
void MODEL4Check(std::vector<std::vector<int> >& map, int row, int col, int& max);
void MODEL5Check(std::vector<std::vector<int> >& map, int row, int col, int& max);
void CheckMax(std::vector<std::vector<int> >& map, int model, int row, int col, int& max);

int main() {

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    //0.Enter input
    std::cin >> N >> M;
    std::vector<std::vector<int> > map(N);
    for(int i=0; i<N; i++) {
        map[i].resize(M, 0);
        for(int j=0; j<M; j++) {
            std::cin >> map[i][j];
        }
    }

    //map check
    /*
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            std::cout << map[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "\n\n";
    */

    //1.Check max
    int max=0;
    for(int row=0; row<N; row++) {
        for(int col=0; col<M; col++) {
            CheckMax(map, MODEL1, row, col, max);
            CheckMax(map, MODEL2, row, col, max);
            CheckMax(map, MODEL3, row, col, max);
            CheckMax(map, MODEL4, row, col, max);
            CheckMax(map, MODEL5, row, col, max);
        }
    }

    std::cout << max;


    return 0;
}


void MODEL1Check(std::vector<std::vector<int> >& map, int row, int col, int& max)
{

    //MODEL1
    // ㅁㅁㅁㅁ : 2 cases // 2 rotate 
    int sum=0;
    if(col+3 < M) { //case 1: ㅁㅁㅁㅁ
        sum = map[row][col] + map[row][col+1] + map[row][col+2] + map[row][col+3];
        max = (max > sum) ? max : sum;
    }
    if(row+3 < N) { //case 2: [ㅁㅁㅁㅁ]T   //no else if
        sum = map[row][col] + map[row+1][col] + map[row+2][col] + map[row+3][col];
        max = (max > sum) ? max : sum;
    }
}

void MODEL2Check(std::vector<std::vector<int> >& map, int row, int col, int& max)
{           
    //MODEL2
    // ㅁㅁ
    // ㅁㅁ : one case

    int sum=0;

    if(row+1 < N && col+1 < M) {    //case1
        sum = map[row][col] + map[row][col+1] + map[row+1][col] + map[row+1][col+1];
        max = (max > sum) ? max : sum;
    }
}

void MODEL3Check(std::vector<std::vector<int> >& map, int row, int col, int& max)
{
    //MODEL3
    // ㅁ
    // ㅁ
    // ㅁ ㅁ : 8 cases // 4 rotate * 2 fold        
    int sum=0;
    if(row-2 >= 0 && col+1 < M)    //case 1
    {
        sum = map[row][col] + map[row][col+1] + map[row-1][col] + map[row-2][col];
        max = (max > sum) ? max : sum;
    }
    if(row+1 < N && col+2 < M) {  //case2: rotate 1
        sum = map[row][col] + map[row][col+1] + map[row][col+2] + map[row+1][col];
        max = (max > sum) ? max : sum;
    }
    if(row+2 < N && col-1 >=0) {  //case3: rotate2
        sum = map[row][col] + map[row][col-1] + map[row+1][col] + map[row+2][col];
        max = (max > sum) ? max : sum;
    }
    if(row-1 >=0 && col-2 >=0) {  //case4: rotate3
        sum = map[row][col] + map[row][col-1] + map[row][col-2] + map[row-1][col];
        max = (max > sum) ? max : sum; 
    }
    if(row-2 >=0 && col-1 >=0) {  //case5: sym1
        sum = map[row][col] + map[row][col-1] + map[row-1][col] + map[row-2][col];
        max = (max > sum) ? max : sum;  
    }
    if(row-1 >=0 && col+2 < M) {  //case6: sym1 + rotate1
        sum = map[row][col] + map[row][col+1] + map[row][col+2] + map[row-1][col];
        max = (max > sum) ? max : sum;
    }
    if(row+2 < N && col+1 < M) {  //case7: sym1 + r2
        sum = map[row][col] + map[row][col+1] + map[row+1][col] + map[row+2][col];
        max = (max > sum) ? max : sum;
    }
    if(row+1 < N && col-2 >= 0) {  //case8: s1 + r3
        sum = map[row][col] + map[row][col-1] + map[row][col-2] + map[row+1][col];
        max = (max > sum) ? max : sum;
    }
}

void MODEL4Check(std::vector<std::vector<int> >& map, int row, int col, int& max)
{
    //MODEL4
    // ㅁ
    // ㅁ ㅁ
    //    ㅁ : 4 cases // 2 rotate * 2 fold

    int sum=0;
    if(row+2 < N && col+1 < M){ //case1
        sum = map[row][col] + map[row+1][col] + map[row+1][col+1] + map[row+2][col+1];
        max = (max > sum) ? max : sum;
    }
    if(row+1 < N && col-2 >= 0){ //case2: 1r
        sum = map[row][col] + map[row][col-1] + map[row+1][col-1] + map[row+1][col-2];
        max = (max > sum) ? max : sum;
    }
    if(row+2 < N && col-1 >= 0){ //case3: 1s
        sum = map[row][col] + map[row+1][col] + map[row+1][col-1] + map[row+2][col-1];
        max = (max > sum) ? max : sum;
    }
    if(row-1 >= 0 && col-2 >= 0){ //case4: 1s + 1r
        sum = map[row][col] + map[row][col-1] + map[row-1][col-1] + map[row-1][col-2];
        max = (max > sum) ? max : sum;
    }
}

void MODEL5Check(std::vector<std::vector<int> >& map, int row, int col, int& max)
{
    //MODEL5
    // ㅁ ㅁ ㅁ
    //    ㅁ     : 4 cases // 4 rotate

    int sum=0;
    if(row+1 < N && col+2 < M) {  //case1
        sum = map[row][col] + map[row][col+1] + map[row][col+2] + map[row+1][col+1];
        max = (max > sum) ? max : sum;
    }
    if(row+2 < N && col-1 >= 0) {  //case2: 1r
        sum = map[row][col] + map[row+1][col] + map[row+1][col-1] + map[row+2][col];
        max = (max > sum) ? max : sum;
    }
    if(row-1 >= 0 && col-2 >= 0) {  //case3: 2r
        sum = map[row][col] + map[row][col-1] + map[row][col-2] + map[row-1][col-1];
        max = (max > sum) ? max : sum;
    }
    if(row-2 >= 0 && col+1 < M) {  //case4: 3r
        sum = map[row][col] + map[row-1][col] + map[row-1][col+1] + map[row-2][col];
        max = (max > sum) ? max : sum;
    }
}

void CheckMax(std::vector<std::vector<int> >& map, int model, int row, int col, int& max) {
    int sum=0;
    switch(model) {
        case(MODEL1):
            MODEL1Check(map, row, col, max);
            break;

        case(MODEL2):
            MODEL2Check(map, row, col, max);
            break;

        case(MODEL3):
            MODEL3Check(map, row, col, max);
            break;

        case(MODEL4):
            MODEL4Check(map, row, col, max);
            break;

        case(MODEL5):
            MODEL5Check(map, row, col, max);
            break;
    }
}