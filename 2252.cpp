#include<iostream>
#include<queue>
#include<vector>



int main()
{
    int N=0, M=0;
    std::cin >> N >> M;
    std::vector<int> degree(N, 0);
    std::vector<int> graph[N];
/*
    for(int i=0; i<N; i++) {
        v.push_back(0);     // student no. x : x-1, value : v[x-1]
    }
*/

    int std_buf1=0, std_buf2=0;
    for(int i=0; i<M; i++) {    //index: student no, value: order
        std::cin >> std_buf1 >> std_buf2;
        degree[std_buf2-1]++;
        graph[std_buf1-1].push_back(std_buf2-1);
    }

    std::queue<int> q;
    for(int i=0; i<N; i++) {
        if(degree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()){

        int cur = q.front();
        q.pop();
        std::cout << cur+1 << ' ';

        for(int i=0; i<graph[cur].size(); i++) {

            degree[graph[cur][i]]--;
            if(degree[graph[cur][i]] == 0)
                q.push(graph[cur][i]);

        }
    }




    return 0;
}