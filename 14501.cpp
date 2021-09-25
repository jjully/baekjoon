//Baekjoon 14501
//for all case, if do or not => DFS !!

#include<iostream>
#include<vector>

using namespace std;

int N=0;

//fcns
void DFS(std::vector<int>& T, std::vector<int>& Pay, int cDay, int cPay, int& max);

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);


    std::cin >> N;
    std::vector<int> T(N+1, 0);
    std::vector<int> Pay(N+1, 0);

    for(int i=1; i<=N; i++) {
        std::cin >> T[i] >> Pay[i];
    }

    //time & pay check
    /*
    std::cout << '\n';
    for(int i=1; i<=N; i++) {
        std::cout << T[i] << ' ' << Pay[i] << '\n';
    }
    std::cout << "\n\n";
    */


    int cDay = 1, cPay = 0, max = 0;
    DFS(T, Pay, cDay, cPay, max);
    std::cout << max;


    return 0;
}

void DFS(std::vector<int>& T, std::vector<int>& Pay, int cDay, int cPay, int& max)
{
    if( cDay == (N+1) ) {
        max = (max > cPay) ? max : cPay;
        return;
    }
    else if ( cDay > (N+1) ) { return; }

    max = (max > cPay) ? max : cPay;

    int nextDay = cDay + T[cDay];
    int nextPay = cPay + Pay[cDay];

    DFS(T, Pay, cDay+1, cPay, max); //if don't work today, same pay and go to tmr
    DFS(T, Pay, nextDay, nextPay, max); //if do work today, add pay and jump to nextDay

}
