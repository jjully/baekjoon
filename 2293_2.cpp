#include<iostream>
#include<vector>


int main()
{

    //0. Enter input
    int n=0, k=0;
    std::cin >> n >> k;
    std::vector<int> coin(n);
    std::vector<int> dp(k+1);

    for(int i=0; i<n; i++)
        std::cin >> coin[i];
    
    //1. dp
    dp[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=coin[i]; j<k+1; j++) {
            dp[j] += dp[ j - coin[i] ];
        }
    }

    std::cout << dp[k];


    return 0;
}