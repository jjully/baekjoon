#include<iostream>
#include<queue>
#include<vector>

int main()
{
    
    std::queue<int> q;
    std::vector<int> degree, ans;
    std::vector<std::vector<int> > adj;

    int N=0, M=0;
    std::cin>> N >> M;
    degree.resize(N);
    adj.resize(N);

    for(int i=0; i<M; i++) {
        int to=0, from=0;
        std::cin >> to >> from;

        adj[from].push_back(to);    //adj[x] <- x 
        degree[to]++;   //how many arrows x get
    }

    for(int i=1; i<=N; i++) {   //if i don't have arrows left
        if(degree[i-1] == 0)
            q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int next:adj[cur])
        {
            degree[next]--;

            if(degree[next]==0)
                q.push(next);
        }

        ans.push_back(cur);
    }


    for(int i=ans.size()-1; i>=0; i--) {
        std::cout << ans[i];
    }


    return 0;
}