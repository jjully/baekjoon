//emoticons
//minimum time: BFS!

//3 options
    //1. copy emoticons to clipboard
    //2. attach clipboard to screen
    //3. delete one emoticon


#include<iostream>
#include<deque>

class state{

    public:
        int screen;
        int clipboard;
        int cnt;

    state(int _screen=1, int _clipboard=0, int _cnt=0) {
        screen = _screen;
        clipboard = _clipboard;
        cnt = _cnt;
    }

};

int S=0;
//std::deque<int> screen, clipboard, cnt; //{screen, time}
std::deque<state> dq;
bool tried[1001][1001];    //tried[x][y]: x: sc y: cb

int BFS();

int main() {

    std::cin >> S;
    /*
    screen.push_back(1);
    clipboard.push_back(0);
    cnt.push_back(0);
    */
    //tried[1][] = 0;
    tried[1][0] = true;
    dq.push_back(state(1, 0, 0));
    //BFS();
    std::cout << BFS();


    return 0;
}

int BFS() {

    //int clipboard = 0;
    while(1) {

        if(dq.empty()) {
            std::cout << "deque is empty. ERROR!! \n";
            exit(-1);
        }
        
        int sc = dq.front().screen;
        int cb = dq.front().clipboard;
        int t = dq.front().cnt;
        
        dq.pop_front();

        if(sc == 0 && cb == 0) continue;
        if(sc == S) return t;
        //state: (screen, clipboard, time)
        //1. copy emoticons to clipboard
        if(sc != cb && tried[sc][sc] != true) {
            tried[sc][sc] = true;
            dq.push_back(state(sc, sc, t+1));
        }

        //2. attach clipboard to screen
        if(cb != 0 && sc+cb <= 1000 && tried[sc+cb][cb] != true) { 
            dq.push_back(state(sc+cb, cb, t+1));
            tried[sc+cb][cb] = true;
            }

        //3. delete one emoticon
        if((sc-1) >= 0 && tried[sc-1][cb] != true){
            dq.push_back(state(sc-1, cb, t+1));
            tried[sc-1][cb] = true;
            }




    //3 options
        //1. copy emoticons to clipboard
        //2. attach clipboard to screen
        //3. delete one emoticon



    }



}