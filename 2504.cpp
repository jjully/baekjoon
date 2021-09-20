#include<iostream>
#include<stack>
#include<cstring>
#define MAX 30

void init_arr(int arr[], int arr_size, int value)
{
    for(int i=0; i<arr_size; i++)
        arr[i] = value;
}

int cal(std::string str, int str_size)
{
    int level = 0, index = 0;
    int num[MAX/2];
    init_arr(num, MAX/2, 0);
    std::stack<char> s; //stack only has '(' or '['

    //  (, [ -> level up // ), ] -> level down
    do{
        if((str[index] == '(') || (str[index] == '['))
        {
            s.push(str[index]);
            level++;
            index++;
        }
        else if(str[index] == ')')
        {
            //1. error check
            if((s.empty()) || (s.top() != '('))
                return 0;
            
            //2. index-1 check
            level--;
            if((str[index-1] == ')') || (str[index-1] == ']'))  //mul
            {
                num[level] += num[level+1] * 2;
                num[level+1] = 0;
            }
            else if(num[level] == 0)   //mul but if first value, just put
                num[level] = 2;
            else    //add
                num[level]+=2;

            s.pop();
            index++;
        }
        else if(str[index] == ']')
        {
            //1. error check
            if((s.empty()) || (s.top() != '['))
                return 0;
            
            //2. index-1 check
            level--;
            if((str[index-1] == ')') || (str[index-1] == ']'))  //mul
            {
                num[level]+= num[level+1] * 3;
                num[level+1] = 0;
            }
            else if(num[level] == 0)   //mul but if first value, just put
                num[level] = 3;
            else    //add
                num[level]+=3;

            s.pop();
            index++;
        }
        else
        {
            return 0;
        }  



    } while(index != str_size);

    if(!s.empty()){
        return 0;
    }
    else
        return num[0];

}

int main()
{
    //1. input
    std::string str;
    int index = 0;

    std::cin >> str; //need to change input //use strsize for index

    index = str.length();

    std::cout << cal(str, index);

    return 0;
}