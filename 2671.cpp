#include<iostream>
#include<string>
#include<regex>

int main() {

    std::string str;
    std::cin >> str;
    std::string pattern = "(100+1+|01)+";
    if(std::regex_match(str, std::regex(pattern))) std::cout << "SUBMARINE";
    else std::cout << "NOISE";


    return 0;
}