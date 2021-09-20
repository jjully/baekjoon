#include<iostream>
#include<vector>
//#include<set>

/*
class cases {
    private:
        int idx;
        int num;
    
    public:

        cases(int idx, int num) {
            idx = idx;
            num = num;
        }
        int GetIdx() {
            return idx;
        }
        int GetNum() {
            return num;
        }
        ~cases();
};
*/

int main()
{

    //0. Enter input
    int N=0;
    std::cin >> N;
    
    //1. check if N is not bigger than N
    if(N <= 10){
        std::cout << N;
        return 0;
    }

    //2. if not, start to find no.
    //2-1. base condition (input 20)
    std::vector<int> cur;

    cur.push_back(0);
    cur.push_back(2);
    int cnt = 10;
    
    while(1) {
        int order = cur.size();
        bool flag = true;
        for(int i = (order-1); i>0; i--) {

            if(cur[i] <= cur[i-1]) {    //if not eligible
                if(cur[i] == 9) {
                    cur[i] = 0;
                    if(i == (order-1)) {
                        cur.push_back(1);
                    }
                    else {
                        cur[i+1]++;
                    }
                }
                cur[i]++;

                for(int j=i-1; j >= 0; j--)
                    cur[j] = 0;

                flag = false;
                break;
            }   //else keep checking ex. 421 4->2->1
        }

        if ( flag == true ) {
            cnt++;
            if(cnt == N) break;
            cur[0]++;
        }

    }

    for(int i=1; i<cur.size(); i++) {
        for(int j=cur.size()-1; j>=i; j--) {
            cur[j]*=10;
        }
    }

    int ans = 0;
    for(int i=0; i<cur.size(); i++)
        ans += cur[i];


    std::cout << ans;
    return 0;
}