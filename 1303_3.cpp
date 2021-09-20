//war-battle

#include<iostream>
#include<deque>
#include<string>
#include<stack>


void DFS(std::deque<std::string>& map, std::deque<bool>& visited, std::pair<int, int>& p, int& cnt);
bool leftcondition(std::deque<std::string>& map, std::deque<bool>& visited, std::pair<int, int>& p);
bool rightcondition(std::deque<std::string>& map, std::deque<bool>& visited, std::pair<int, int>& p);
bool upcondition(std::deque<std::string>& map, std::deque<bool>& visited, std::pair<int, int>& p);
bool downcondition(std::deque<std::string>& map, std::deque<bool>& visited, std::pair<int, int>& p);

int N=0, M=0;   //N: horizontal, M: vertical
int Wpow=0, Bpow=0;

int main()
{
    //0. Enter input
    std::cin >> N >> M;
    std::deque<std::string> map;
    std::deque<bool> visited(N*M, false); // visited[row][col] = visited[M*row + col];

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
   for(int row=0; row<M; row++) {
       for(int col=0; col<N; col++) {
           if(visited[N*row + col] == false){
                int cnt=0;
                //s.push(position(col, row));
                std::pair<int, int> pos;
                pos.first = row;
                pos.second = col;
                DFS(map, visited, pos, cnt);
                if(map[row][col] == 'W') Wpow += cnt*cnt;
                else Bpow += cnt*cnt;
           }
       }
   }

   std::cout << Wpow << ' ' << Bpow;

    return 0;
}

void DFS(std::deque<std::string>& map, std::deque<bool>& visited, std::pair<int, int>& p, int& cnt){
    cnt++;
    visited[N*p.first + p.second] = true;     // visited[col][row] = visited[M*col + row];
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
void DFS_ver2(std::deque<std::string>& map, std::deque<bool>& visited, int& cnt) {

    while(1) {
        if( s.empty() ) return;

        position temp( s.top().getY(), s.top().getX() );
        if(visited[M*])
    }
}
*/
bool leftcondition(std::deque<std::string>& map, std::deque<bool>& visited, std::pair<int, int>& pos) {
    if( (pos.second > 0) && (map[pos.first][pos.second] == map[pos.first][pos.second-1]) && (visited[N*pos.first+pos.second-1] == false) )
        return true;
    else
        return false;
}

bool rightcondition(std::deque<std::string>& map, std::deque<bool>& visited, std::pair<int, int>& pos) {
    if( (pos.second < N-1) && (map[pos.first][pos.second] == map[pos.first][pos.second+1]) && (visited[N*pos.first+pos.second+1] == false) )
        return true;
    else
        return false;
}

bool upcondition(std::deque<std::string>& map, std::deque<bool>& visited, std::pair<int, int>& pos) {
    if( (pos.first > 0) && (map[pos.first][pos.second] == map[pos.first-1][pos.second]) && (visited[N*(pos.first-1)+pos.second] == false) )
        return true;
    else
        return false;
}

bool downcondition(std::deque<std::string>& map, std::deque<bool>& visited, std::pair<int, int>& pos) {
    if( (pos.first < M-1) && (map[pos.first][pos.second] == map[pos.first+1][pos.second]) && (visited[N*(pos.first+1)+pos.second] == false) )
        return true;
    else
        return false;
}
