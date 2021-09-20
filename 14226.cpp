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
        int time;

    state(int _screen=1, int _clipboard=0, int _time=0) {
        screen = _screen;
        clipboard = _clipboard;
        time = _time;
    }

};

int S=0;
//std::deque<int> screen, clipboard, cnt; //{screen, time}
std::deque<state> dq;
bool tried[1001];

int BFS();

int main() {

    std::cin >> S;
    /*
    screen.push_back(1);
    clipboard.push_back(0);
    cnt.push_back(0);
    */
    tried[0] = true;
    tried[1] = true;
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

        int sc = screen.front();
        int cb = clipboard.front();
        int t = cnt.front();
        screen.pop_front();
        clipboard.pop_front();
        cnt.pop_front();
        
        if(sc == 0 && cb == 0) continue;
        if(sc == S) return t;
        //state: (screen, clipboard, time)
        //1. copy emoticons to clipboard
        //dq.push_back(state(screen, screen, time+1));
        screen.push_back(sc);
        clipboard.push_back(sc);
        cnt.push_back(t+1);
        //2. attach clipboard to screen
        //if(cb != 0) { dq.push_back(state(screen+cb, cb, time+1)); }
        if(cb != 0) {
            screen.push_back(sc+cb);
            clipboard.push_back(cb);
            cnt.push_back(t+1);
        }

        //3. delete one emoticon
        //dq.push_back(state(screen-1, cb, time+1));
        screen.push_back(sc-1);
        clipboard.push_back(cb);
        cnt.push_back(t+1);




    //3 options
        //1. copy emoticons to clipboard
        //2. attach clipboard to screen
        //3. delete one emoticon



    }



}