#include<iostream>
#include<vector>

template <typename T>
void swap(T& x, T& y);

int main()
{

    int N = 0, max = 0;
    int count = 0;
    //0. Enter the input
    std::cin >> N;
    std::vector<char> candy[N];
    //bool flag = true; //flag for finding max of a block of same components
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            char temp = 0;
            std::cin >> temp;
            candy[i].push_back(temp);
        }
    }

    //1. max change w/ horizontal swap
    for(int i=0; i<N; i++) {
        for(int j=0; j<(N-1); j++) {
            if(candy[i][j] != candy[i][j+1]) { // swap when two components are different
                swap(candy[i][j], candy[i][j+1]);
            }


            //check left, up, down for candy[i][j]
            //initialize
            int vertical_idx = i;
            int horizontal_idx = j;
            int left = 0, right = 0, up_j = 0, down_j = 0, up_jj = 0, down_jj = 0;
            int vertical_max = 0, horizontal_max = 0;
            //left
            while(horizontal_idx != 0) {
                horizontal_idx--;
                if (candy[i][horizontal_idx] == candy[i][j]) left++;
                else break;
            }
            //up
            while(vertical_idx != 0) {
                vertical_idx--;
                if(candy[vertical_idx][j] == candy[i][j]) up_j++;
                else break;
            }
            //down
            vertical_idx = i;
            while(vertical_idx != (N-1)) {
                vertical_idx++;
                if(candy[vertical_idx][j] == candy[i][j]) down_j++;
                else break;
            }

            //check right, up, down for candy[i][j+1]
            //initialize
            vertical_idx = i;
            horizontal_idx = j+1;
            //right
            while(horizontal_idx != (N-1)) {
                horizontal_idx++;
                if (candy[i][horizontal_idx] == candy[i][j+1]) right++;
                else break;
            }
            //up
            while(vertical_idx != 0) {
                vertical_idx--;
                if(candy[vertical_idx][j+1] == candy[i][j+1]) up_jj++;
                else break;
            }
            //down
            vertical_idx = i;
            while(vertical_idx != (N-1)) {
                vertical_idx++;
                if(candy[vertical_idx][j+1] == candy[i][j+1]) down_jj++;
                else break;
            }
            //check horizontal_max and vertical_max
            //if candy[i][j] == candy[i][j+1], horizontal max = left + right + 1
            if(candy[i][j] == candy[i][j+1]) horizontal_max = left+right+2;
            else if(left > right) horizontal_max = left+1;
            else horizontal_max = right+1;

            //vertical max
            if( (up_j + down_j) > (up_jj + down_jj) ) vertical_max = up_j + down_j + 1;
            else vertical_max = up_jj + down_jj + 1;

            //real max
            int max_temp = 0;
            if(horizontal_max > vertical_max) max_temp = horizontal_max;
            else max_temp = vertical_max;

            if(max_temp > max) max = max_temp;

            if(max == N) {
                std::cout << max;
                return 0;
            }

            if(candy[i][j] != candy[i][j+1]) { // swap back
                swap(candy[i][j], candy[i][j+1]);
            }            
        }
    }


    //2. max change w/ vertical swap
    for(int i=0; i<N; i++) {
        for(int j=0; j<(N-1); j++) {
            if(candy[j][i] != candy[j+1][i]) { // swap when two components are different
                swap(candy[j][i], candy[j+1][i]);
            }


            //check left, up, down for candy[i][j]
            //initialize
            int vertical_idx = j;
            int horizontal_idx = i;
            int up = 0, down = 0, left_j = 0, right_j = 0, left_jj = 0, right_jj = 0;
            int vertical_max = 0, horizontal_max = 0;
            //up
            while(vertical_idx != 0) {
                vertical_idx--;
                if (candy[vertical_idx][i] == candy[j][i]) up++;
                else break;
            }
            //left
            while(horizontal_idx != 0) {
                horizontal_idx--;
                if(candy[j][horizontal_idx] == candy[j][i]) left_j++;
                else break;
            }
            //right
            horizontal_idx = i;
            while(horizontal_idx != (N-1)) {
                horizontal_idx++;
                if(candy[j][horizontal_idx] == candy[j][i]) right_j++;
                else break;
            }

            //check right, up, down for candy[i][j+1]
            //initialize
            vertical_idx = j+1;
            horizontal_idx = i;
            //down
            while(vertical_idx != (N-1)) {
                vertical_idx++;
                if (candy[vertical_idx][i] == candy[j+1][i]) down++;
                else break;
            }
            //left
            while(horizontal_idx != 0) {
                horizontal_idx--;
                if(candy[j+1][horizontal_idx] == candy[j+1][i]) left_jj++;
                else break;
            }
            //right
            horizontal_idx = i;
            while(horizontal_idx != (N-1)) {
                horizontal_idx++;
                if(candy[j+1][horizontal_idx] == candy[j+1][i]) right_jj++;
                else break;
            }
            //check horizontal_max and vertical_max
            //if candy[j][i] == candy[j+1][i], vertical_max = up + down + 1
            if(candy[j][i] == candy[j+1][i]) vertical_max = up+down+1;
            else if(up > down) vertical_max = up+1;
            else vertical_max = down+1;

            //horizontal max
            if( (left_j + right_j) > (left_jj + right_jj) ) horizontal_max = left_j + right_j + 1;
            else horizontal_max = left_jj + right_jj + 1;

            //real max
            int max_temp = 0;
            if(horizontal_max > vertical_max) max_temp = horizontal_max;
            else max_temp = vertical_max;

            if(max_temp > max) max = max_temp;

            if(max == N) {
                std::cout << max;
                return 0;
            }

            if(candy[j][i] != candy[j+1][i]) { // swap when two components are different
                swap(candy[j][i], candy[j+1][i]);
            }           
        }
    }

    std::cout << max;

    return 0;
}

template <typename T>
void swap(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}