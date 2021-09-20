#include<iostream>

int main(){

    int64_t S=0;
    std::cin >> S;
    int64_t i=1, sum=1;
    int64_t ans = 0;

    while( (S-sum) > i ) {
        i++;
        sum+=i;
    } 

    if(  (S-sum) < 0 ) ans = i-1;
    else ans = i;

    std::cout << ans;

    return 0;
}