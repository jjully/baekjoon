//war-battle

#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<deque>
/*
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
*/
void DFS(std::vector<std::string>& map, std::vector<bool>& visited, std::pair<int, int>& p, int& cnt);
bool leftcondition(std::vector<std::string>& map, std::vector<bool>& visited, std::pair<int, int>& p);
bool rightcondition(std::vector<std::string>& map, std::vector<bool>& visited, std::pair<int, int>& p);
bool upcondition(std::vector<std::string>& map, std::vector<bool>& visited, std::pair<int, int>& p);
bool downcondition(std::vector<std::string>& map, std::vector<bool>& visited, std::pair<int, int>& p);

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
                std::pair<int, int> pos;
                pos.first = col;
                pos.second = row;
                DFS(map, visited, pos, cnt);
                if(map[col][row] == 'W') Wpow += cnt*cnt;
                else Bpow += cnt*cnt;
           }
       }
   }

   std::cout << Wpow << ' ' << Bpow;

    return 0;
}

void DFS(std::vector<std::string>& map, std::vector<bool>& visited, std::pair<int, int>& p, int& cnt){
    cnt++;
    visited[M*p.first + p.second] = true;     // visited[col][row] = visited[M*col + row];
    //check left
    if( leftcondition(map, visited, p) == true ) {
        p.second--;
        DFS(map, visited, p, cnt);
        p.second++;
        }
    //check right
    if( rightcondition(map, visited, p) == true ) {
        p.second++;
        DFS(map, visited, p, cnt);
        p.second--;
        }
    //check up
    if( upcondition(map, visited, p) == true ) {
        p.first--;
        DFS(map, visited, p, cnt);
        p.first++;
        }
    //check down
    if( downcondition(map, visited, p) == true ) {
        p.first++;
        DFS(map, visited, p, cnt);
        p.first--;
        }
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
bool leftcondition(std::vector<std::string>& map, std::vector<bool>& visited, std::pair<int, int>& pos) {
    if( (pos.second > 0) && (map[pos.first][pos.second] == map[pos.first][pos.second-1]) && (visited[M*pos.first+pos.second-1] == false) )
        return true;
    else
        return false;
}

bool rightcondition(std::vector<std::string>& map, std::vector<bool>& visited, std::pair<int, int>& pos) {
    if( (pos.second < N-1) && (map[pos.first][pos.second] == map[pos.first][pos.second+1]) && (visited[M*pos.first+pos.second+1] == false) )
        return true;
    else
        return false;
}

bool upcondition(std::vector<std::string>& map, std::vector<bool>& visited, std::pair<int, int>& pos) {
    if( (pos.first > 0) && (map[pos.first][pos.second] == map[pos.first-1][pos.second]) && (visited[M*(pos.first-1)+pos.second] == false) )
        return true;
    else
        return false;
}

bool downcondition(std::vector<std::string>& map, std::vector<bool>& visited, std::pair<int, int>& pos) {
    if( (pos.first < M-1) && (map[pos.first][pos.second] == map[pos.first+1][pos.second]) && (visited[M*(pos.first+1)+pos.second] == false) )
        return true;
    else
        return false;
}