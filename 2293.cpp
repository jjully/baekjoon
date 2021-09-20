#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
//use int32_t

int32_t cnt = 0;
std::vector<int> v;
void DFS(int sum, int idx);

int main() {

    int n=0, k=0;
    std::cin >> n >> k;
    //int32_t cnt = 0;
    std::priority_queue<int, std::vector<int>, std::less<int> > pq;

    //0. Enter input
    for(int i=0; i<n; i++) {
        int temp = 0;
        std::cin >> temp;
        v.push_back(temp);
    }

    sort( v.begin(), v.end() );
    /*
    for(int i=0; i<n; i++) {
    v.push_back(pq.top());
    pq.pop();
    }
*/
    //1. DFS
    DFS(k, 0);

    std::cout << cnt;

    return 0;
}

void DFS(int sum, int idx) {

    if( sum == 0 ) {
        cnt++;
        return;
    }

    int coin = v[idx];

    if( idx == (v.size()-1) ) {
        if(sum == (sum/coin)*coin ) cnt++;
        return;
    }

    for(int i=0; i<= (sum/coin); i++) {
        DFS( (sum - coin*i), idx+1 );
    }

}