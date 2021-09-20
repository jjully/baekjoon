//emoticons
//minimum time: BFS!

//3 options
    //1. copy emoticons to clipboard
    //2. attach clipboard to screen
    //3. delete one emoticon


#include<iostream>
#include<deque>

uint32_t S=0, cnt=0;
std::deque<uint32_t> state[2]; //{screen, clipboard} // 31~16: screen, 15~0: clipboard
bool tried[1001];

uint32_t BFS();

int main() {

    std::cin >> S;
    state[0].push_back(1<<16);
    tried[0] = true;
    tried[1] = true;
    //BFS();
    std::cout << BFS();


    return 0;
}

uint32_t BFS() {
    
    uint32_t idx = 0;
    while(1) {

        if(state[idx].empty()) {
            if(state[!idx].empty()) {
                std::cout << "deque is empty. ERROR!! \n";
                exit(-1);
            }

            idx=!idx;
            cnt++;
        }

        uint32_t cb = state[idx].front() & 0b1111111111111111;
        uint32_t sc = state[idx].front() >> 16;

        state[idx].pop_front();
        
        if(sc == 0 && cb == 0) continue;
        if(sc == S) return cnt;
        //state: (screen, clipboard, time)
 
        //dq.push_back(state(screen, screen, time+1));
        //int temp = sc;

        //1. copy emoticons to clipboard (screen, screen)
        if(sc != cb) { state[!idx].push_back( sc + (sc<<16) ); }
        //2. attach clipboard to screen (screen+clipboard, clipboard)
        if( (tried[sc+cb] != true) && (cb != 0) ) {
            state[!idx].push_back({cb + ((cb+sc)<<16)});
            }

        //3. delete one emoticon (screen-1, clipboard)
        if(tried[sc-1] != true){
            state[!idx].push_back(cb + ((sc-1)<<16));
        }

    }



}