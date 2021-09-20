#include<iostream>
#include<string>
#include<vector>

std::vector<int> getPi(std::string str);
void findstr(std::string S, std::string P);

int main()
{   
    std::string S, P;

    std::cin >> S;
    std::cin >> P;

    findstr(S, P);

    return 0;
}

std::vector<int> getPi(std::string str) {

    int strLength = str.length();
    int j=0, i=1;
    std::vector<int> p(strLength, 0);
    for(i=1; i<strLength; i++) {
        while( (j > 0) && (str[i] != str[j]) ) {
            j = p[j - 1];
        }
        if(str[i] == str[j]) {
            p[i] = ++j;
        }
    }
    return p;
}

void findstr(std::string S, std::string P) {
    

    std::vector<int> pi = getPi(P);
    int sLength = S.length(), pLength = P.length();
    int j=0;
    for(int i=0; i<sLength; i++) {
        while( j>0 && S[i]!=P[j]) {
            j = pi[j-1];
        }
        if(S[i]==P[j]){
            if( j == (pLength-1) ) {
                std::cout << 1;
                return;
            }
            else { j++; }
        }
    }

    std::cout << 0;
}