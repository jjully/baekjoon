#include<iostream>
#include<vector>

int N;

class position {
    private:
        int row;
        int col;
        int state;  //0: horizontal 1: vertical 2: diagonal
    
    public:
    position(int _row = 0, int _col = 1, int _state = 0) {
        row = _row;
        col = _col;
        state = _state;
    }
    int getRow() { return row; }
    int getCol() { return col; }
    int getState() { return state; }
    ~position(){;}
};


void DFS(std::vector<int>& house, int& cnt, position pos);
bool verticalMove(std::vector<int>& house, position pos);
bool horizontalMove(std::vector<int>& house, position pos);
bool diagonalMove(std::vector<int>& house, position pos);

int main(){

    //0. Enter input
    std::cin >> N;
    std::vector<int> house(N*N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int temp = 0;
            std::cin >> temp;
            house[N*i+j] = temp;    //i == row, j == col
        }
    }
/* // house check
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            std::cout << house[N*i+j];
        }
        std::cout << std::endl;
    }
*/

    int cnt = 0;
    DFS(house, cnt, position());
    std::cout << cnt;

    return 0;
}

void DFS(std::vector<int>& house, int& cnt, position pos) {
    if( (pos.getRow() == (N-1)) && (pos.getCol() == (N-1)) ) {
        cnt++;
        return;
    }

    switch(pos.getState()) {
        //horizontal
        case(0):
        {
            //horizontal move
            if( horizontalMove(house, pos) == true )
                DFS(house, cnt, position(pos.getRow(), pos.getCol()+1, 0));
            //diagonal move
            if( diagonalMove(house, pos) == true )
                DFS(house, cnt, position(pos.getRow()+1, pos.getCol()+1, 2));            
            break;
        }
        //vertical
        case(1):
        {
            //vertical move
            if( verticalMove(house, pos) == true )
                DFS(house, cnt, position(pos.getRow()+1, pos.getCol(), 1));
            //diagonal move
            if( diagonalMove(house, pos) == true )
                DFS(house, cnt, position(pos.getRow()+1, pos.getCol()+1, 2));  
            break;
        }
        //diagonal
        case(2):
        {
            //horizontal move
            if( horizontalMove(house, pos) == true )
                DFS(house, cnt, position(pos.getRow(), pos.getCol()+1, 0));
            //vertical move
            if( verticalMove(house, pos) == true )
                DFS(house, cnt, position(pos.getRow()+1, pos.getCol(), 1));
            //diagonal move
            if( diagonalMove(house, pos) == true )
                DFS(house, cnt, position(pos.getRow()+1, pos.getCol()+1, 2));  
            break;
        }
    }


}

bool horizontalMove(std::vector<int>& house, position pos) {
    if( (pos.getCol() != (N-1)) && (house[N*pos.getRow()+pos.getCol()+1]!=1) )
        return true;
    else
        return false;
}

bool diagonalMove(std::vector<int>& house, position pos) {
    if( (pos.getRow() != (N-1)) && (house[N*(pos.getRow()+1)+pos.getCol()]!=1) 
                && (pos.getCol() != (N-1)) && (house[N*pos.getRow()+pos.getCol()+1]!=1) 
                && (house[N*(pos.getRow()+1)+pos.getCol()+1]!=1))
                return true;
    else
                return false;
}

bool verticalMove(std::vector<int>& house, position pos) {
    if( (pos.getRow() != (N-1)) && (house[N*(pos.getRow()+1)+pos.getCol()]!=1) )
        return true;
    else
        return false;
}