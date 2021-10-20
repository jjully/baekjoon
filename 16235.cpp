//baekjoon 16235
//simulation
//spring, summer, autumn, winter

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

int N=0, M=0, K=0;
std::vector<std::vector< std::vector<int> > > Tree; //Tree[row*N+col]: pq for trees which are located at (row, col)
std::vector<std::vector<int> > DDong; //size 121
std::vector<std::vector<int> > Annual;
std::vector<std::vector< std::vector<int> > > Death;
int drow[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dcol[] = { 0, -1, -1, -1, 0, 1, 1, 1 };

//fcns
void Input();
void solution();
//int calAge(std::priority_queue<int>& Tree);
template <typename T>
void v2DInit(std::vector<std::vector<T> >& v, int row, int col, T val);
void Spring();
void Summer();
void Autumn();
void Winter();
int CalTree();
void Reproduction(int row, int col);

void Input() {

    std::cin >> N >> M >> K;
    v2DInit(DDong, N, N, 5);    //start with 5
    v2DInit(Annual, N, N, 0);
    
    Tree.resize(N);
    Death.resize(N);
    for(int i=0; i<N; i++) {    //N*N tree info with pq on each locataion
        Tree[i].resize(N);
        Death[i].resize(N);
    }

    for(int i=0; i<N; i++) {    //annual ddong
        for(int j=0; j<N; j++) {
            std::cin >> Annual[i][j];
        }
    }

    int tmpRow=0, tmpCol=0, tmpAge=0;
    for(int i=0; i<M; i++) {    //tree info.
        std::cin >> tmpRow >> tmpCol >> tmpAge;
        tmpRow--;
        tmpCol--;
        Tree[tmpRow][tmpCol].push_back(tmpAge);
    }

}

void Spring() {

    int DDongLeft = 0;
    for(int i=0; i<N; i++) {    //for all point
        for(int j=0; j<N; j++) {
            //////
            int treeSize = Tree[i][j].size();
            if(treeSize == 0) continue;
    
            std::sort(Tree[i][j].begin(), Tree[i][j].end());    // 1, 2, 3, ...
            DDongLeft = DDong[i][j];
            std::vector<int> tmpTree;

            for(int k=0; k<treeSize; k++) {
                int age=Tree[i][j][k];
                if( (DDongLeft-age) >= 0 ) { //feed and age++
                    DDongLeft -= age;
                    tmpTree.push_back(age+1);
                }
                else {
                    Death[i][j].push_back(Tree[i][j][k]);
                }
            }

            Tree[i][j].swap(tmpTree);
            DDong[i][j] = DDongLeft;

            //////
        }
    }
}

void Summer() {
    
    //add Death to DDong
    //reset Death

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {    //for all points

            int deathSize = Death[i][j].size();
            for(int k=0; k<deathSize; k++) {
                DDong[i][j] += (Death[i][j][k]/2);
            }

            Death[i][j].clear();        //reset Death[i][j]
            std::vector<int>().swap(Death[i][j]);


        }
    }


}

void Reproduction(int row, int col) {

    for(int i=0; i<8; i++) {
        int nextRow = row+drow[i];
        int nextCol = col+dcol[i];
        if( nextRow<0 || nextRow>=N || nextCol<0 || nextCol>=N ) continue;
        else {
            Tree[nextRow][nextCol].push_back(1);
        }
    }

}

void Autumn() {

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {    //for all points

            int treeSize = Tree[i][j].size();
            for(int k=0; k<treeSize; k++) {

                if(Tree[i][j][k]%5 == 0) {
                    Reproduction(i, j);
                }

            }


        }
    }

}

void Winter() {

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            DDong[i][j] += Annual[i][j];
        }
    }

}

int CalTree() {

    int cnt=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cnt += Tree[i][j].size();
        }
    }

    return cnt;
}


void solution() {

    for(int i=0; i<K; i++) {    //for all year
        //spring
        Spring();
        //summer
        Summer();
        //autumn
        Autumn();
        //winter
        Winter();
    }

    std::cout << CalTree();

}

int main() {

    Input();
    solution();

    return 0;
}

template <typename T>
void v2DInit(std::vector<std::vector<T> >& v, int row, int col, T val) {

    v.clear();
    std::vector<std::vector<T> >().swap(v);

    v.resize(row);
    for(int i=0; i<row; i++) {
        v[i].resize(col, val);
    }
}