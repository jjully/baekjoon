#include<iostream>
#include<string>
#include<deque>

void solution(std::string str);

int main() {

    std::string str;
    std::cin >> str;

    solution(str);

    return 0;
}


//pattern: (100+1+|01)+;
void solution(std::string str) {

    bool startFlag = true;
    std::deque<char> v;

    //input to v
    for(int i=0; i<str.size(); i++) {
        v.push_back(str[i]);
    }

    bool dup_flag = false;
    while(!v.empty()) {
        switch(v.front()) {
            case('0'): {  //pattern starts with '0'
                v.pop_front();
                if(v.empty()) { //v.front() is always 0 or 1 // or v is empty
                    std::cout << "NOISE";
                    return;
                } 
                else if(v.front() == '0') {
                    if(dup_flag == true) {
                        v.push_front('0');
                        v.push_front('1');
                        dup_flag = false;
                        continue;
                    }
                    else {
                        std::cout << "NOISE";
                        return;
                    }
                }
                else {  //v.front() == '1'
                    v.pop_front();
                    continue;   //01 pattern is over
                }
            }
            case('1'): {  //pattern starts with '1'
                v.pop_front();
                if(v.size() < 2) {
                    std::cout << "NOISE";
                    return;
                }
                else if(v[0] == '0' && v[1] == '0') {   //pattern 100+ complete
                    while(1) { //stop when v is empty or v.front is '1'
                        v.pop_front();
                        if(v.empty()) {  //case 1. v is already empty
                            std::cout << "NOISE";
                            return;
                        }
                        else if(v.front() == '1') break;
                    }

                    //case 2. v.front() is 1 //pattern 100~1~ is complete
                    dup_flag = false;
                    while(1) { //stop when v is empty or v.front is '0'
                        v.pop_front();
                        if(v.empty()) {
                            std::cout << "SUBMARINE";
                            return;
                        }
                        else if(v.front() == '0') break;
                        else dup_flag = true;
                    }
                }
                else {
                    std::cout << "NOISE";
                    return;
                }
            }
        }

    }
    //when string is completed with 01 pattern
    std::cout << "SUBMARINE";


}