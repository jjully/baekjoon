#include<iostream>
#include<vector>
#define TOP 0
#define BOTTOM 1
#define LEFT 2
#define RIGHT 3
#define FRONT 4
#define REAR 5

//fcns
void playgame(std::vector<int>& map, std::vector<int>& dice, std::vector<int>& order, std::pair<int, int> pos);
void Move(std::vector<int>& map, std::vector<int>& dice, int order, std::pair<int, int>& pos);


int N=0, M=0, K=0;
enum {EAST=1, WEST, NORTH, SOUTH};
int dcol[] = {0, 1, -1, 0, 0};
int drow[] = {0, 0, 0, -1, 1};  //no meaning, E, W, N, S

void playgame();

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int row=0, col=0;
    std::cin >> N >> M >> row >> col >> K;

    std::vector<int> map(N*M, 0);
    int tmp=0;
    for(int r=0; r<N; r++){   //Enter map Info.
        for(int c=0; c<M; c++) {
            std::cin >> map[M*r+c];
        }
    }

    //map check
    /*
    for(int row=0; row<N; row++){   //Enter map Info.
        for(int col=0; col<M; col++) {
            std::cout << map[M*row+col];
        }
        std::cout << '\n';
    }
    std::cout << "\n\n";
    */
   
    std::vector<int> order(K, 0);   //Enter order Info.
    for(int i=0; i<K; i++)
    {
        std::cin >> order[i];
    }

    //solution fcn call
    std::vector<int> dice(6, 0);
    std::pair<int, int> pos = {row, col};
    playgame(map, dice, order, pos);


    return 0;
}

void playgame(std::vector<int>& map, std::vector<int>& dice, std::vector<int>& order, std::pair<int, int> pos)
{

    int orderNo=0, rowNo=0, colNo=0;
    bool vertical = false;
    while(orderNo != order.size())
    {
        int cOrder = order[orderNo];
        Move(map, dice, cOrder, pos);
        /*
        if(cOrder == EAST || cOrder == WEST)
            vertical = false;
        else
            vertical = true;

        switch(vertical) {
            case(true):

                colNo = 1;
                rowNo = 0;
                break;
        }
        */
        orderNo++;
    }



}

void Move(std::vector<int>& map, std::vector<int>& dice, int order, std::pair<int, int>& pos)
{
    //1. position check
    int newRow = pos.first+drow[order];
    int newCol = pos.second+dcol[order];
    if(newRow < 0 || newRow >= N || newCol < 0 || newCol >= M)  //no print and do not follow order
        return;
    else{       //Move
        pos.first = newRow;
        pos.second = newCol;
    }

    //2. dice change
    int tmp=0;
    switch(order) {
        case(EAST): case(WEST):
            tmp = dice[RIGHT];
            if(order == EAST) {
                dice[RIGHT] = dice[TOP];
                dice[TOP] = dice[LEFT];
                dice[LEFT] = dice[BOTTOM];
                dice[BOTTOM] = tmp;
            }
            else if(order == WEST) {
                dice[RIGHT] = dice[BOTTOM];
                dice[BOTTOM] = dice[LEFT];
                dice[LEFT] = dice[TOP];
                dice[TOP] = tmp;
            }
            break;
        case(NORTH): case(SOUTH):
            tmp = dice[TOP];
            if(order == NORTH) {
                dice[TOP] = dice[FRONT];
                dice[FRONT] = dice[BOTTOM];
                dice[BOTTOM] = dice[REAR];
                dice[REAR] = tmp;
            }
            else if(order == SOUTH) {
                dice[TOP] = dice[REAR];
                dice[REAR] = dice[BOTTOM];
                dice[BOTTOM] = dice[FRONT];
                dice[FRONT] = tmp;
                }
            break;
    }
    //3. BOTTOM & MAP interaction
    if(map[M*pos.first + pos.second] == 0)
        map[M*pos.first + pos.second] = dice[BOTTOM];
    else {
        dice[BOTTOM] = map[M*pos.first + pos.second];
        map[M*pos.first + pos.second] = 0;
    }

    std::cout << dice[TOP] << '\n';
}