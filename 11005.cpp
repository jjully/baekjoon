#include<iostream>
#include<vector>
#include<string>

using namespace std;

void solution(int num, int B);

int main(){
    
    int num=0;
    int B;
    std::cin >> num >> B;
    solution(num, B);
    //std::cout << solution(num, B) << std::endl;

    return 0;
}

void solution(int num, int B) {

    if( num==0 ) {
        std::cout << '0';
        return;
    }

    string answer = "";
    int value=num, left=0;
    //vector<string> v;

    while(value!=0) {

        left = value % B;
        value = value / B;

        if(left<10) answer+=(char)(left+'0');
        else answer+=(char)((left-10)+'A');
    }

    int SIZE=answer.size();
    for(int i=(SIZE-1); i>=0; i--) {
        std::cout << answer[i];
    }

    //return answer;
}