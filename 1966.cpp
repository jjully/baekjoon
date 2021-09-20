#include<iostream>
#include<queue>
#include<vector>

int main()
{

    int T=0, N=0, M=0;
    int value[9];



    std::cin >> T;
    std::vector<int> ans;
    for(int i=0; i<T; i++) {
        
        for(int i=0; i<9; i++) { value[i] = 0; }

        std::cin >> N >> M;
        std::queue<int> priority;
        int M_priority=0;

        for(int j=0; j<N; j++) {    //input and save M_priority
            int temp=0;
            std::cin >> temp;
            value[temp-1]++;
            if( j==M ) {
                M_priority = temp;
                priority.push(0);
                continue;
                }

            priority.push(temp);
        }
        
        int biggerCount = 0, sameCount = 0;
/*
        for(int k=0; k<N; k++) {    //look around queue and check how many bigger elements there are
            if(priority.front() > M_priority) { biggerCount++; }
            priority.push(priority.front());
            priority.pop();
        }
*/

        for(int i=M_priority; i<9; i++)
        {
            biggerCount+=value[i];
        }

        int ans_temp = biggerCount;
        int idx = 8;

        while( biggerCount != 0 ) {
            if(value[idx] == 0) {
                idx--; 
                continue; }
            if( priority.front() == (idx + 1) ) {
                biggerCount--;
                value[idx]--;
                priority.pop();
            }
            else {
                priority.push(priority.front());
                priority.pop();
            }
        }

        //only M_priority>=priority elements are left
        while( priority.front() != 0 ) {
            if( priority.front() == M_priority ) {
                sameCount++;
            }
            priority.pop();
        }


        //std::cout << (ans_temp + sameCount + 1) << std::endl;
        ans.push_back( (ans_temp + sameCount + 1) );

    }

    for(int m=0; m<ans.size(); m++) {
        std::cout << ans[m] << std::endl;
    }


    return 0;
}