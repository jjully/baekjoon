//war-battle

#include<iostream>
#include<vector>
#include<string>
#include<stack>

class position {

    public:
        int x;
        int y;
        //int state;

        position(int _y = 0, int _x = 0) {
            x = _x;
            y = _y;
            //state = _state;
        }
        //void setX(int _x) { x = _x; }
        //void setY(int _y) { y = _y; }
        //int getX() { return x; }
        //int getY() { return y; }
        //int getState() { return state; }
        ~position(){;}
};

void DFS(std::vector<std::string>& map, std::vector<bool>& visited, position p, int& cnt);
bool leftcondition(std::vector<std::string>& map, std::vector<bool>& visited, position& pos);
bool rightcondition(std::vector<std::string>& map, std::vector<bool>& visited, position& pos);
bool upcondition(std::vector<std::string>& map, std::vector<bool>& visited, position& pos);
bool downcondition(std::vector<std::string>& map, std::vector<bool>& visited, position& pos);

int N=0, M=0;   //N: horizontal, M: vertical
int Wpow=0, Bpow=0;
//std::stack<position> s;

int main()
{
    //0. Enter input
    std::cin >> N >> M;
    std::vector<std::string> map;
    std::vector<bool> visited(N*M, false); // visited[col][row] = visited[M*col + row];

    std::string temp;
    for(int i=0; i<M; i++) {
        std::cin >> temp;
        map.push_back(temp);
    }

    //check map
    /*
    for(int i=0; i<M; i++) {
        std::cout << map[i] << std::endl;
    }
    */
   for(int col=0; col<M; col++) {
       for(int row=0; row<N; row++) {
           if(visited[M*col + row] == false){
                int cnt=0;
                //s.push(position(col, row));
                DFS(map, visited, position(col, row), cnt);
                if(map[col][row] == 'W') Wpow += cnt*cnt;
                else Bpow += cnt*cnt;
           }
       }
   }

   std::cout << Wpow << ' ' << Bpow;

    return 0;
}

void DFS(std::vector<std::string>& map, std::vector<bool>& visited, position pos, int& cnt){
    cnt++;
    visited[M*pos.y + pos.x] = true;     // visited[col][row] = visited[M*col + row];
    //check left
    if( leftcondition(map, visited, pos) == true ) { DFS(map, visited, position(pos.y, pos.x-1), cnt); }
    //check right
    if( rightcondition(map, visited, pos) == true ) { DFS(map, visited, position(pos.y, pos.x+1), cnt); }
    //check up
    if( upcondition(map, visited, pos) == true ) { DFS(map, visited, position(pos.y-1, pos.x), cnt); }
    //check down
    if( downcondition(map, visited, pos) == true ) { DFS(map, visited, position(pos.y+1, pos.x), cnt); }
}
/*
void DFS_ver2(std::vector<std::string>& map, std::vector<bool>& visited, int& cnt) {

    while(1) {
        if( s.empty() ) return;

        position temp( s.top().getY(), s.top().getX() );
        if(visited[M*])
    }
}
*/
bool leftcondition(std::vector<std::string>& map, std::vector<bool>& visited, position& pos) {
    if( (pos.x > 0) && (map[pos.y][pos.x] == map[pos.y][pos.x-1]) && (visited[M*pos.y+pos.x-1] == false) )
        return true;
    else
        return false;
}

bool rightcondition(std::vector<std::string>& map, std::vector<bool>& visited, position& pos) {
    if( (pos.x < N-1) && (map[pos.y][pos.x] == map[pos.y][pos.x+1]) && (visited[M*pos.y+pos.x+1] == false) )
        return true;
    else
        return false;
}

bool upcondition(std::vector<std::string>& map, std::vector<bool>& visited, position& pos) {
    if( (pos.y > 0) && (map[pos.y][pos.x] == map[pos.y-1][pos.x]) && (visited[M*(pos.y-1)+pos.x] == false) )
        return true;
    else
        return false;
}

bool downcondition(std::vector<std::string>& map, std::vector<bool>& visited, position& pos) {
    if( (pos.y < M-1) && (map[pos.y][pos.x] == map[pos.y+1][pos.x]) && (visited[M*(pos.y+1)+pos.x] == false) )
        return true;
    else
        return false;
}