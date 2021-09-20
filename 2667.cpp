#include<iostream>
#include<vector>
#include<string>
#include<queue>

std::vector<std::string> village;
std::priority_queue<int, std::vector<int>, std::greater<int> > comp_cnt;   //or greater

int find(int x, int y, int N, std::vector<bool>& visited, int house_cnt);


int main() {

    //0. Enter input
    int N=0;
    std::cin >> N;
    std::vector<bool> visited(N*N, false);

    std::string temp;
    for(int i=0; i<N; i++) {
        std::cin >> temp;
        village.push_back(temp);
    }

    //1. find
    //start BFS when village[x][y] == 1 && visited[x][y]==false
    //and village_cnt++, pq.push(component_cnt);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(visited[N*i+j] == true) continue;
            else if(village[i][j] == '1') {
                comp_cnt.push( find(j, i, N, visited, 0) );
            }
            else {
                visited[N*i+j] = true;
            }
        }
    }

    std::cout << comp_cnt.size() << '\n';
    int size = comp_cnt.size();

    for(int i=0; i<size; i++) {
        std::cout << comp_cnt.top() << std::endl;
        comp_cnt.pop();
    }

    
    /*  //village checking
    std::cout << std:: endl;
    for(int i=0; i<N; i++) {
        std::cout << village[i];
        std::cout << std::endl;
    }
    */


    return 0;
}

int find(int x, int y, int N, std::vector<bool>& visited, int house_cnt){
    
    visited[N*y+x] = true;
    house_cnt++;

    //left check
    if( x > 0 ) {
        if( (village[y][x-1] == '1') && (visited[N*y+x-1] == false) ) {
            house_cnt = find(x-1, y, N, visited, house_cnt);
        }
    }
    //right check
    if( x < (N-1) ) {
        if( (village[y][x+1] == '1') && (visited[N*y+x+1] == false) ) {
            house_cnt = find(x+1, y, N, visited, house_cnt);
        }
    }
    //up check
    if( y > 0 ) {
        if( (village[y-1][x] == '1') && (visited[N*(y-1)+x] == false) ){
            house_cnt = find(x, y-1, N, visited, house_cnt);
        }
    }
    //down check
    if( y < (N-1) ) {
        if( (village[y+1][x] == '1') && (visited[N*(y+1)+x] == false) ){
            house_cnt = find(x, y+1, N, visited, house_cnt);
        }
    }

    return house_cnt;

}