//DFS and BFS

#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<list>

int N=0, M=0, V=0;
std::stack<int> s;
std::queue<int> q;

void DFS(std::list<int>* edge, std::vector<int>& visited, std::list<int>& ans);
void BFS(std::list<int>* edge, std::vector<int>& visited, std::list<int>& ans);



int main()
{

    //0. Enter input
    std::cin >> N >> M >> V;
    std::list<int> edge[N+1];
    int start = 0, end = 0;
    //k <---> each edge[k].element is connected
    for(int i=0; i<M; i++) {
        std::cin >> start >> end;
        edge[start].push_back(end);
        edge[end].push_back(start);
    }
    //sort edge information with increasing order
    for(int i=0; i<=N; i++) {
        edge[i].sort();                 //find which one is increasing and which is decreasing order
    }

    std::vector<int> visitedDFS(N+1, 0);
    std::vector<int> visitedBFS(N+1, 0);
    std::list<int> ansDFS;
    std::list<int> ansBFS;

    s.push(V);
    DFS(edge, visitedDFS, ansDFS);
    q.push(V);
    visitedBFS[V] = 1;
    BFS(edge, visitedBFS, ansBFS);

    int size = ansDFS.size();
    std::list<int>::iterator iter = ansDFS.begin();
    for(int i=0; i<size; i++) {
        std::cout << *iter;
        if(i != (size-1)) std::cout << ' ';
        ++iter;
    }
    std:: cout << std:: endl;
    size = ansBFS.size();
    iter = ansBFS.begin();
    for(int i=0; i<size; i++) {
        std::cout << *iter;
        if(i != (size-1)) std::cout << ' ';
        ++iter;
    }

    return 0;
}


void DFS(std::list<int>* edge, std::vector<int>& visited, std::list<int>& ans) {
    
    if( s.empty() ) return;
    int vertex = s.top();
    s.pop();
    visited[vertex] = 1;
    ans.push_back(vertex);
    int size = edge[vertex].size();
    std::list<int>::iterator iter = edge[vertex].begin();
    for(int i=0; i<size; i++) {
        if(visited[*iter] == 0) {
            s.push( *iter );
            DFS(edge, visited, ans);
            //s.pop();
        }
        ++iter;
    }
}


void BFS(std::list<int>* edge, std::vector<int>& visited, std::list<int>& ans) {

    while(1) {
        if( q.empty() ) return;
        int vertex = q.front();
        q.pop();


        ans.push_back(vertex);
        int size = edge[vertex].size();
        std::list<int>::iterator iter = edge[vertex].begin();
        for(int i=0; i<size; i++) {
            if(visited[*iter] == 0) {
                visited[*iter] = 1;
                q.push( *iter );
            }
            ++iter;
        }
    }

    
    return;
}