#include<iostream>
#include<algorithm>
#include<vector>

//#define MAX 10000

int main(){

    //0. Enter input
    int n=0, k=0;
    std::cin >> n >> k;
    std::vector<int> coin(n);
    int temp = 0;
    for(int i=0; i<n; i++) {
        std::cin >> temp;
        coin[i] = temp;
    }

    std::vector<int> min(k+1, 0);

    //1. base condition
    
    for(int i=0; i<n; i++) {
        if(coin[i] > k) continue;
        min[ coin[i] ] = 1;
        //std::cout <<"min[" << coin[i] << "]:" << min[coin[i]] << std::endl;
    }

    //2. find min
    for(int i=0; i<n; i++) {
        for(int j=(coin[i]+1); j<=k; j++) {

            if(min[ j - coin[i] ] == 0) continue;    //2-1. cannot express with additional 1 coin[i]
            else if( ((min[j-coin[i]] + 1) < min[j]) || (min[j] == 0) )
                    min[j] = min[j-coin[i]] + 1;
        }
    }
    /*for(int i=0; i<=k; i++)
        std::cout << i << ':' << min[i] << std::endl;
    */
   if(min[k] == 0) std::cout << -1;
   else std::cout << min[k];
    return 0;
}