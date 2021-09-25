#include<iostream>
#include<vector>
//using namespace std;

int N=0;
int dcol[] = {1, 0, -1, 0};   //right, down, left, up
int drow[] = {0, 1, 0, -1};

enum {EMPTY, APPLE, BODY, WALL};  //0: empty, 1: apple, 2:body, 3:wall

void SnakeGame(std::vector<int>& map, std::pair<int, char>* way, int WAY_SIZE, int& end_time);
int MoveOn(std::vector<int>& map, std::vector<std::pair<int, int> >&snake, int timeLeft, int curTime, int dIdx, bool& flag);

int main()
{
    

    //0. Enter input
    int K=0;
    scanf("%d", &N);
    scanf("%d", &K);

    std::vector<int> map((N+2)*(N+2), EMPTY);
    int row=0, col=0;
    for(int i=0; i<K; i++)
    {
        scanf("%d %d", &row, &col);
        map[(N+2)*row+col] = APPLE;
    }

    //make wall
    for(int i=0; i<(N+2); i++){
        for(int j=0; j<(N+2); j++){
            if(i == 0 || i == (N+1)) {
                map[(N+2)*i+j] = WALL;
            }
            else {
                if(j == 0 || j == (N+1)) {
                    map[(N+2)*i+j] = WALL;
                }
            }
        }
    }

    //map check
    /*
    for(int row=0; row<(N+2); row++) {
        for(int col=0; col<(N+2); col++) {
            printf("%d ", map[(N+2)*row+col]);
        }
        printf("\n");
    }
    printf("\n\n");
    */
    int L=0, t=0;
    char direction;
    scanf("%d", &L);
    std::pair<int, char> way[L];
    for(int i=0; i<L; i++){
        scanf("%d %c", &t, &direction);
        way[i] = {t, direction};
    }

    int end_time = 0;
    SnakeGame(map, way, L, end_time);

    printf("%d", end_time);
    
    return 0;
}

void SnakeGame(std::vector<int>& map, std::pair<int, char>* way, int WAY_SIZE, int& curTime)
{
    std::vector<std::pair<int, int> > snake;
    snake.push_back({1,1}); // {row, col}
    map[(N+2)*1+1] = BODY;

    int idx=0, dIdx=0, changeTime=0;
    char direction;
    bool flag = false;
    while(1) { //keep going until head meets body or wall

        if(idx < WAY_SIZE) {
            changeTime = way[idx].first;
        }
        else {  //if no more direction change left
            changeTime = curTime+N+2;   //maximum time
        }

        
        flag = false;
        curTime = MoveOn(map, snake, changeTime, curTime, dIdx, flag);
        //end_time += t;

        if(flag == true) { //if snake meet BODY or WALL
            return;
        }
        
        direction = way[idx].second;
        switch(direction) { //change direction
            case('D'):
                dIdx = (dIdx+1)%4;
                break;
            case('L'):
                dIdx = (dIdx+3)%4;
                break;
        }
        idx++;
    }
}

int MoveOn(std::vector<int>& map, std::vector<std::pair<int, int> >&snake, int changeTime, int curTime, int dIdx, bool& flag) {

    while(curTime != changeTime) {
        curTime++;
        std::pair<int, int> head = {snake[0].first, snake[0].second};   // {row, col}
        int Next = ((N+2)*(head.first+drow[dIdx]) + head.second+dcol[dIdx]);
        if( (map[Next] == BODY) || (map[Next] == WALL) ) {                         //1. BODY
            flag = true;
            return curTime;
        }
        else {
            std::pair<int, int> tail = {snake[snake.size()-1].first, snake[snake.size()-1].second};
            if(map[Next] == APPLE) {                               //2. APPLE
                snake.push_back(tail);
                for(int i=(snake.size()-2); i>=0; i--) {
                    if(i == 0) {     //if head, move 
                        snake[i].first += drow[dIdx];
                        snake[i].second += dcol[dIdx];
                        map[Next] = BODY;
                        }
                    else {
                        snake[i].first = snake[i-1].first;
                        snake[i].second = snake[i-1].second;
                    }
                }
                continue;
            }
            else {                      //3. EMPTY
                for(int i=(snake.size()-1); i>=0; i--) {
                    if(i == 0) {     //if head
                    /*
                        if(snake.size() == 1) {
                            map[snake[i].first + snake[i].second] = EMPTY;
                        }
                        */
                        snake[i].first += drow[dIdx];
                        snake[i].second += dcol[dIdx];
                        map[Next] = BODY;

                    }
                    else {
                        snake[i].first = snake[i-1].first;
                        snake[i].second = snake[i-1].second;
                    }
                }
                map[(N+2)*tail.first + tail.second] = EMPTY;
            }
        }

    }


    return curTime;

/*
    switch(dIdx) {
        case(0) :   //right
            while(t != timeLeft) {
                t++;
                int Next = ((N+2)*head.first + head.second+1);
                if( (map[Next] == BODY) || (map[Next] == WALL) ) {                         //1. BODY
                    flag = true;
                    return t;
                }
                else if(map[Next] == APPLE) {                   //2. APPLE
                    std::pair<int, int> tail = {snake[snake.size()-1].first, snake[snake.size()-1].second};
                    snake.push_back(tail);
                    for(int i=(snake.size()-2); i>=0; i--) {
                        if(i == 0) { snake[i].second++; } //if head, move right
                        else {
                            snake[i].first = snake[i-1].first;
                            snake[i].second = snake[i-1].second;
                        }
                    }
                }
                else {                      //3. EMPTY
                    for(int i=(snake.size()-1); i>=0; i--) {
                        if(i == 0) { snake[i].second++; } //if head, move right
                        else {
                            snake[i].first = snake[i-1].first;
                            snake[i].second = snake[i-1].second;
                        }
                    }
                }
            }
            break;
        
        case(1) :   //down
            while(t != timeLeft) {
                t++;
                int Next = ((N+2)*(head.first+1) + head.second);
                if( (map[Next] == BODY) || (map[Next] == WALL) ) {                         //1. BODY
                    flag = true;
                    return t;
                }
                else if(map[Next] == APPLE) {                   //2. APPLE
                    std::pair<int, int> tail = {snake[snake.size()-1].first, snake[snake.size()-1].second};
                    snake.push_back(tail);
                    for(int i=(snake.size()-2); i>=0; i--) {
                        if(i == 0) { snake[i].first++; } //if head, move down
                        else {
                            snake[i].first = snake[i-1].first;
                            snake[i].second = snake[i-1].second;
                        }
                    }
                }
                else {                      //3. EMPTY
                    for(int i=(snake.size()-1); i>=0; i--) {
                        if(i == 0) { snake[i].first++; } //if head, move right
                        else {
                            snake[i].first = snake[i-1].first;
                            snake[i].second = snake[i-1].second;
                        }
                    }
                }
            }
            break;

        case(2) :   //left
            while(t != timeLeft) {
                t++;
                int Next = ((N+2)*head.first + head.second-1);
                if( (map[Next] == BODY) || (map[Next] == WALL) ) {                         //1. BODY
                    flag = true;
                    return t;
                }
                else if(map[Next] == APPLE) {                   //2. APPLE
                    std::pair<int, int> tail = {snake[snake.size()-1].first, snake[snake.size()-1].second};
                    snake.push_back(tail);
                    for(int i=(snake.size()-2); i>=0; i--) {
                        if(i == 0) { snake[i].second--; } //if head, move left
                        else {
                            snake[i].first = snake[i-1].first;
                            snake[i].second = snake[i-1].second;
                        }
                    }
                }
                else {                      //3. EMPTY
                    for(int i=(snake.size()-1); i>=0; i--) {
                        if(i == 0) { snake[i].second--; } //if head, move right
                        else {
                            snake[i].first = snake[i-1].first;
                            snake[i].second = snake[i-1].second;
                        }
                    }
                }
            }
            break;

        case(3) :   //up
            while(t != timeLeft) {
                t++;
                int Next = ((N+2)*(head.first-1) + head.second);
                if( (map[Next] == BODY) || (map[Next] == WALL) ) {                         //1. BODY
                    flag = true;
                    return t;
                }
                else if(map[Next] == APPLE) {                   //2. APPLE
                    std::pair<int, int> tail = {snake[snake.size()-1].first, snake[snake.size()-1].second};
                    snake.push_back(tail);
                    for(int i=(snake.size()-2); i>=0; i--) {
                        if(i == 0) { snake[i].first--; } //if head, move down
                        else {
                            snake[i].first = snake[i-1].first;
                            snake[i].second = snake[i-1].second;
                        }
                    }
                }
                else {                      //3. EMPTY
                    for(int i=(snake.size()-1); i>=0; i--) {
                        if(i == 0) { snake[i].first--; } //if head, move right
                        else {
                            snake[i].first = snake[i-1].first;
                            snake[i].second = snake[i-1].second;
                        }
                    }
                }
            }
            break;
    }
    */
}

