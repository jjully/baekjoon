#include<iostream>

int main()
{

    int N=0, S=0;
    std::cin >> N >> S;
    int arr[N];
    int start = 0;
    int end = 0;

    int max = 0;

    for(int i=0; i<N; i++) {
        std::cin >> arr[i];
        max+=arr[i];
        }
        if(max < S) {
            std::cout << 0;
            return 0;
        }
        else if(max == S) {
            std::cout << N;
            return 0;
        }


    int min_length = N;
    int value = 0;
    bool flag = false;
    while(1) {
        if( end == (N+1) ) { break; }
        else if ( start == end ) {
            end++;
            flag = false;
            }
        else {
            switch(flag) {
                case(true):
                    value-=arr[start-1];
                    break;
                case(false):
                    value+=arr[end-1];
                    break;
            }

            //check min_length and decide which way to go
            if( (value >= S) && (min_length > (end-start)) ) { min_length = (end-start); }

            //decide which way to go
            if(value >= S) {
                start++;
                flag = true;
            }
            else {
                end++;
                flag = false;
            }
        }
    }

    if( min_length == N ) { std::cout << 0; }
    else { std::cout << min_length; }


    return 0;
}