#include<iostream>
#include<queue>

int main()
{

    int N=0, K=0;

    std::cin >> N >> K;
    std::queue<int> q, result;

    for(int i=1; i<=N; i++){ q.push(i); }

    int count = 0;
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        count = (count+1)%K;
        if(count == 0) { result.push(temp); }
        else { q.push(temp); }
    }

    std::cout << '<';
    while( !result.empty() ) {
        std::cout << result.front();
        result.pop();
        if( !result.empty() ) std::cout << ", ";
        }
    std::cout << '>';

    return 0;
}