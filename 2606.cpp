//virus
//find no. of connected computer -> no need to visit all components
//BFS!!

#include<iostream>
#include<deque>
#include<queue>

std::queue<int> q;

int N=0, cnt=0;
void BFS(std::deque<int>* graph, std::deque<bool>& visited);

int main(){


    //0. Enter input
    int K=0;
    std::cin >> N >> K;
    std::deque<int> graph[N];
    std::deque<bool> visited(N, false);

    int temp0=0, temp1=0;
    for(int i=0; i<K; i++) {
        std::cin >> temp0 >> temp1;
        graph[temp0-1].push_back(temp1-1);    //deque is better than array because no need to search all when find connected comp.
        graph[temp1-1].push_back(temp0-1);
    }

    q.push(0);
    visited[0] = true;
    BFS(graph, visited);

    std::cout << cnt;

    return 0;
}

void BFS(std::deque<int>* graph, std::deque<bool>& visited) {

    while(1) {
        if( q.empty() ) return;

        int cur = q.front();
        q.pop();

        for(int i=0; i<graph[cur].size(); i++) {
            if( visited[ graph[cur][i] ] == true ) continue;
            else {
                cnt++;
                visited[ graph[cur][i] ] = true;
                q.push(graph[cur][i]);
            }
        }
    }

}