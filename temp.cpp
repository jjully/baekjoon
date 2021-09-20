#include<iostream>
#include<vector>
#include<string>
using namespace std;
string solution(vector<int> numbers);

int main() {
    vector<int> numbers;
    int N=0;
    std::cin >> N;
    int temp = 0;
    for(int i=0;i<N; i++) {
        std::cin >> temp;
        numbers.push_back(temp);
    }

    std::cout << solution(numbers);

    return 0;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<int> numCnt(1001, 0);
    //vector<vector<int> > digit(3);
    
    for(int i=0; i<numbers.size(); i++) {
        numCnt[numbers[i]]++;   //1000은 카운트만
        /*
        if(numbers[i] >= 0 && numbers[i] < 10) digit[0].push_back(numbers[i]);  //한자리수 벡터
        else if(numbers[i] >= 10 && numbers[i] < 100) digit[1].push_back(numbers[i]);   //두자리수 벡터
        else if(numbers[i] >= 100 && numbers[i] < 1000) digit[2].push_back(numbers[i]); //세자리수 벡터
        */
    }
    
    vector<int> arr;
    int one=0, ten=0, hundred=0;
    for(int i=100; i<1000; i++) {   //sorting
        one = i%10;
        hundred = i/100;
        ten = i - hundred*100;
        //ten -= one;
        ten /= 10;
        //cout << ten;
        if(hundred == one) {
            if(hundred == ten) {
                arr.push_back(i%10);  //xxx 꼴이면 x도 넣고 xx도 넣음
                arr.push_back(i/10);
                arr.push_back(i);
                continue;
            }
            else if(hundred > ten){  //xyx 꼴인데 x>y
                arr.push_back(i/10);
                arr.push_back(i);
                continue;
            }
            else {  //xyx 꼴인데 x<y
                arr.push_back(i);
                arr.push_back(i/10);
                continue;
            }
        }
        arr.push_back(i);
    }
    
    
    for(int i=arr.size()-1; i>=0; i--) {
        
        for(int j=0; j<numCnt[arr[i]]; j++) {
            answer+=to_string(arr[i]);
        }
        
    }
    
    
    
    //arr check
    /*
    for(int i=arr.size()-1; i>=arr.size()-10; i--) {
        answer+=to_string(arr[i]);
    }
    */
    
    for(int i=0; i<numCnt[1000]; i++) answer+=to_string(1000);
    for(int i=0; i<numCnt[0]; i++) answer+=to_string(0);
    
    
    
    //numCnt check
    /*
    for(int i=0; i<numCnt.size(); i++) {
        if(numCnt[i] == 1) answer+=to_string(i);
    }
    */
    
    
    return answer;
}

