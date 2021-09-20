#include<iostream>
#include<cstring>
#include<vector>
#define MAX 5
using namespace std;

vector<int>arr;
vector<int>result;
int visit[MAX];

void prt_combi(){
    for(int i=0; i<MAX; i++)
    {
        if(visit[i] == true)
        {
            cout << arr[i] << ' ';
        }
    }

    cout << endl;
}

void dfs_combi(int idx, int cnt)
{
    if(cnt == 3)
    {
        prt_combi();
        return;
    }

    for(int i=idx; i<MAX; i++)
    {
        if(visit[i] == true) continue;
        visit[i] = true;
        dfs_combi(i, cnt+1);
        visit[i] = false;
    }
}

int main(){

    for(int i=0; i<MAX; i++)
        arr.push_back(i+1);


    dfs_combi(0,0);
    return 0;
}