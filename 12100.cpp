#include<iostream>
#include<vector>

using namespace std;

int N=0;

void DFS(vector<int>& map, int& max, int cnt);
void maxcheck(vector<int>& map, int& max);
void moveLeft(vector<int>& map);
void moveRight(vector<int>& map);
void moveUp(vector<int>& map);
void moveDown(vector<int>& map);
void printmap(vector<int>& map);


int main()
{

    scanf("%d", &N);
    vector<int> map;   

    int tmp=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%d", &tmp);
            map.push_back(tmp); //map[N*i+j] == row: i, col: j
        }
    }



    int max = 0;
    DFS(map, max, 0);
    printf("%d", max);
    
    //map check
    //printmap(map);

    
    




    return 0;
}

void DFS(vector<int>& map, int& max, int cnt)
{
    maxcheck(map, max);

    if(cnt == 5)
        return;
    
    vector<int> Left, Right, Up, Down;
    Left.resize((int)map.size());
    copy(map.begin(), map.end(), Left.begin());
    moveLeft(Left);
    //check if Left is same with map
    DFS(Left, max, cnt+1);

    Right.resize((int)map.size());
    copy(map.begin(), map.end(), Right.begin());
    moveRight(Right);
    //check if Right is same with map
    DFS(Right, max, cnt+1);

    Up.resize((int)map.size());
    copy(map.begin(), map.end(), Up.begin());
    moveUp(Up);
    //check if Up is same with map
    DFS(Up, max, cnt+1);

    Down.resize((int)map.size());
    copy(map.begin(), map.end(), Down.begin());
    moveDown(Down);
    //check if Down is same with map
    DFS(Down, max, cnt+1);


}

/////moving fcns.//////////////

void moveLeft(vector<int>& map)
{
    //0. add
    int row=0, col=0;
    for(row=0; row<N; row++) {
        for(col=0; col<(N-1); col++) {  //no need to check the last col
            if(map[N*row+col] == 0) continue;  //if empty, pass
            else    //if map[N*row+col] != 0
            {   
                int coltmp = col+1; //next col
                while (coltmp < N) {
                    if(map[N*row+coltmp] == 0){ //find the element which is not 0
                        coltmp++;
                        continue;
                    }
                    else {
                        if(map[N*row+coltmp] == map[N*row+col]) {
                            map[N*row+col] *= 2;
                            map[N*row+coltmp] = 0;
                        }
                        break;
                    }
                }
                col = coltmp-1;
            }
        }
    }

    //1. rearrange
    row=0;
    while(row < N)
    {
        col = 0; 
        int idx = 0;
        while(col <N)
        {
            if(map[N*row+col] != 0)
            {
                col++;
                continue;
            }
            else
            {
                int coltmp = col;
                while(col <N && map[N*row+col] == 0) { col++; }
                if(col <N)
                {
                    map[N*row+coltmp] = map[N*row+col];
                    map[N*row+col] = 0;
                    col = coltmp+1;
                }
            }
        }
        row++;
    }

}


void moveRight(vector<int>&map)
{
    //0. add
    int row=0, col=(N-1);
    for(row=0; row<N; row++) {
        for(col=(N-1); col>0; col--) {  //no need to check the last col
            if(map[N*row+col] == 0) continue;  //if empty, pass
            else
            {   
                int coltmp = col-1;
                while (coltmp >= 0) {
                    if(map[N*row+coltmp] == 0){
                        coltmp--;
                        continue;
                    }
                    else {
                        if(map[N*row+coltmp] == map[N*row+col]) {
                            map[N*row+col] *= 2;
                            map[N*row+coltmp] = 0;
                        }
                        break;
                    }
                }
                col = coltmp+1;
            }
        }
    }

    //1. rearrange
    row=0;
    while(row < N)
    {
        col = (N-1);
        while(col >= 0)
        {
            if(map[N*row+col] != 0)
            {
                col--;
                continue;
            }
            else    //if Left[N*row+col] is 0
            {
                int coltmp = col;
                while(col >= 0 && map[N*row+col] == 0) { col--; }
                if(col >= 0)  //if Left[N*row+col] != 0
                {
                    map[N*row+coltmp] = map[N*row+col];
                    map[N*row+col] = 0;
                    col = coltmp-1;
                }
            }
        }
        row++;
    }

}

void moveUp(vector<int>& map)
{
    //0. add
    int row=0, col=0;
    for(col=0; col<N; col++) {
        for(row=0; row<(N-1); row++) {  //no need to check the last col
            if(map[N*row+col] == 0) continue;  //if empty, pass
            else
            {   
                int rowtmp = row+1;
                while (rowtmp < N) {
                    if(map[N*(rowtmp)+col] == 0){
                        rowtmp++;
                        continue;
                    }
                    else {
                        if(map[N*(rowtmp)+col] == map[N*row+col]) {
                            map[N*row+col] *= 2;
                            map[N*(rowtmp)+col] = 0;
                        }
                        break;
                    }
                }
                row = rowtmp-1;
            }
        }
    }

    //1. rearrange
    col=0;
    while(col < N)
    {
        row = 0;
        while(row <N)
        {
            if(map[N*row+col] != 0)
            {
                row++;
                continue;
            }
            else
            {
                int rowtmp = row;
                while(row <N && map[N*row+col] == 0) { row++; }
                if(row <N)
                {
                    map[N*rowtmp+col] = map[N*row+col];
                    map[N*row+col] = 0;
                    row = rowtmp + 1;
                }
            }
        }
        col++;
    }

}


void moveDown(vector<int>&map)
{
    //0. add
    int col=0, row=(N-1);
    for(col=0; col<N; col++) {
        for(row=(N-1); row>0; row--) {  //no need to check the last col
            if(map[N*row+col] == 0) continue;  //if empty, pass
            else
            {   
                int rowtmp = row-1;
                while (rowtmp >= 0) {
                    if(map[N*(rowtmp)+col] == 0){
                        rowtmp--;
                        continue;
                    }
                    else {
                        if(map[N*(rowtmp)+col] == map[N*row+col]) {
                            map[N*row+col] *= 2;
                            map[N*(rowtmp)+col] = 0;
                        }

                        break;
                    }
                }
                row = rowtmp+1;
            }
        }
    }

    //1. rearrange
    col=0;
    while(col < N)
    {
        row = (N-1);
        while(row >= 0)
        {
            if(map[N*row+col] != 0)
            {
                row--;
                continue;
            }
            else    //if map[N*row+col] is 0
            {
                int rowtmp = row;
                while(row >= 0 && map[N*row+col] == 0) { row--; }
                if(row >= 0)  //if Left[N*row+col] != 0
                {
                    map[N*rowtmp+col] = map[N*row+col];
                    map[N*row+col] = 0;
                    row = rowtmp - 1;
                }
            }
        }
        col++;
    }

}

void maxcheck(vector<int>& map, int& max)
{

    //compare max with the max of new map
    //if new max is bigger, change
    int maxtmp = 0;
    for(int row=0; row<N; row++) {
        for(int col=0; col<N; col++) {
            maxtmp = (maxtmp >= map[N*row+col]) ? maxtmp : map[N*row+col];
        }
    }
    max = (max > maxtmp) ? max : maxtmp;

}

void printmap(vector<int>& map) {
    vector<int> Left, Right, Up, Down;
    Left.resize((int)map.size());
    copy(map.begin(), map.end(), Left.begin());
    moveLeft(Left);
    //check if Left is same with map
    
    printf("\nLEFT:\n");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%d ", Left[N*i+j]);
        }
        printf("\n");
    }

    Right.resize((int)map.size());
    copy(map.begin(), map.end(), Right.begin());
    moveRight(Right);
    //check if Right is same with map
    printf("\nRIGHT:\n");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%d ", Right[N*i+j]);
        }
        printf("\n");
    }

    Up.resize((int)map.size());
    copy(map.begin(), map.end(), Up.begin());
    moveUp(Up);
    //check if Up is same with map
    printf("\nUP:\n");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%d ", Up[N*i+j]);
        }
        printf("\n");
    }

    Down.resize((int)map.size());
    copy(map.begin(), map.end(), Down.begin());
    moveDown(Down);
    //check if Down is same with map
    printf("\nDOWN:\n");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%d ", Down[N*i+j]);
        }
        printf("\n");
    }

}