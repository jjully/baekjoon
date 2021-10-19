//baekjoon 5373
//simulation

//          B
//      L   U   R   D
//          F

//U[9] D[9] L[9] R[9] F[9] B[9]
//check which one is changed for all case
//ex. L- : BUFD이 L과 접한 쪽이 반시계로 돌아감
//tmp하나 두고 돌린 후 마지막에 tmp값을 시작한 면에 저장하면 됨


#include<iostream>
#include<vector>
#include<string>

int N=0;
std::vector<char> UP, DOWN, LEFT, RIGHT, FRONT, BACK;  // x[3*row + col]

//fcns
void InitiateSide();
void Input();
void Solution(std::vector<std::pair<char, char> >& Rotation);
void Rotate(char side, char direction);
void PrintUP();

void InitiateSide() {
                                // x[3*row + col]
    UP.clear();
    std::vector<char>().swap(UP);
    UP.resize(9, 'w');

    DOWN.clear();
    std::vector<char>().swap(DOWN);
    DOWN.resize(9, 'y');

    FRONT.clear();
    std::vector<char>().swap(FRONT);
    FRONT.resize(9, 'r');

    BACK.clear();
    std::vector<char>().swap(BACK);
    BACK.resize(9, 'o');

    LEFT.clear();
    std::vector<char>().swap(LEFT);
    LEFT.resize(9, 'g');

    RIGHT.clear();
    std::vector<char>().swap(RIGHT);
    RIGHT.resize(9, 'b');
    
}
//L- F+ B+ U- D- L+ R+
//
void Input() {

    std::cin >> N;
    //std::string tmpstr;


    for(int i=0; i<N; i++) {
        int cnt=0;
        std::cin >> cnt;
        std::vector<std::pair<char, char> > Rotation;
        Rotation.resize(cnt);

        for(int j=0; j<cnt; j++) {
            std::string tmpstr;
            std::cin >> tmpstr;
            Rotation[j].first = tmpstr[0];
            Rotation[j].second = tmpstr[1];
        }
        InitiateSide();
        Solution(Rotation);
    }

}

void Solution(std::vector<std::pair<char, char> >& Rotation) {

    for(int i=0; i<Rotation.size(); i++) {
        char side = Rotation[i].first;
        char direction = Rotation[i].second;
        Rotate(side, direction);
    }

    PrintUP();
}

void Rotate(char side, char direction) {


//          B
//      L   U   R   D
//          F



//
//              B0 B1 B2
//              B3 B4 B5
//              B6 B7 B8
//
// L0 L1 L2     U0 U1 U2    R0 R1 R2    D0 D1 D2            
// L3 L4 L5     U3 U4 U5    R3 R4 R5    D3 D4 D5            
// L6 L7 L8     U6 U7 U8    R6 R7 R8    D6 D7 D8            
//
//              F0 F1 F2
//              F3 F4 F5
//              F6 F7 F8



//U[9] D[9] L[9] R[9] F[9] B[9]
//check which one is changed for all case
//ex. L- : BUFD이 L과 접한 쪽이 반시계로 돌아감
//tmp하나 두고 돌린 후 마지막에 tmp값을 시작한 면에 저장하면 됨



    std::vector<char> tmp;
    switch(side) {
        case('L'):
            if(direction == '+') {  //CW
                tmp.assign(UP.begin(), UP.end());
                UP[0] = BACK[0];
                UP[3] = BACK[3];
                UP[6] = BACK[6];
                BACK[0] = DOWN[8];
                BACK[3] = DOWN[5];
                BACK[6] = DOWN[2];
                DOWN[8] = FRONT[0];
                DOWN[5] = FRONT[3];
                DOWN[2] = FRONT[6];
                FRONT[0] = tmp[0];
                FRONT[3] = tmp[3];
                FRONT[6] = tmp[6];
                tmp.clear();
                std::vector<char>().swap(tmp);
                tmp.assign(LEFT.begin(), LEFT.end());
                LEFT[0] = tmp[6];
                LEFT[1] = tmp[3];
                LEFT[2] = tmp[0];
                LEFT[3] = tmp[7];
                LEFT[4] = tmp[4];
                LEFT[5] = tmp[1];
                LEFT[6] = tmp[8];
                LEFT[7] = tmp[5];
                LEFT[8] = tmp[2];
            }
            else {  //CCW
                tmp.assign(UP.begin(), UP.end());
                UP[0] = FRONT[0];
                UP[3] = FRONT[3];
                UP[6] = FRONT[6];
                FRONT[0] = DOWN[8];
                FRONT[3] = DOWN[5];
                FRONT[6] = DOWN[2];
                DOWN[8] = BACK[0];
                DOWN[5] = BACK[3];
                DOWN[2] = BACK[6];
                BACK[0] = tmp[0];
                BACK[3] = tmp[3];
                BACK[6] = tmp[6];
                tmp.clear();
                std::vector<char>().swap(tmp);
                tmp.assign(LEFT.begin(), LEFT.end());
                LEFT[0] = tmp[2];
                LEFT[1] = tmp[5];
                LEFT[2] = tmp[8];
                LEFT[3] = tmp[1];
                LEFT[4] = tmp[4];
                LEFT[5] = tmp[7];
                LEFT[6] = tmp[0];
                LEFT[7] = tmp[3];
                LEFT[8] = tmp[6];
            }
        break;
//              D8 D7 D6    D2 D5 D8
//              D5 D4 D3    D1 D4 D7 
//              D2 D1 D0    D0 D3 D6
//              
// L6 L3 L0     B0 B1 B2    R2 R5 R8
// L7 L4 L1     B3 B4 B5    R1 R4 R7
// L8 L5 L2     B6 B7 B8    R0 R3 R6
//
// L0 L1 L2     U0 U1 U2    R0 R1 R2    D0 D1 D2    L0 L1 L2
// L3 L4 L5     U3 U4 U5    R3 R4 R5    D3 D4 D5    L3 L4 L5
// L6 L7 L8     U6 U7 U8    R6 R7 R8    D6 D7 D8    L6 L7 L8
//
// L2 L5 L8     F0 F1 F2    R6 R3 R0 
// L1 L4 L7     F3 F4 F5    R7 R4 R1
// L0 L3 L6     F6 F7 F8    R8 R5 R2
//                          
//              D8 D7 D6    D6 D3 D0
//              D5 D4 D3    D7 D4 D1
//              D2 D1 D0    D8 D5 D2

//CW
//
//  0 1 2       6 3 0
//  3 4 5   --> 7 4 1
//  6 7 8       8 5 2
//CCW
//
//  0 1 2       2 5 8
//  3 4 5   --> 1 4 7
//  6 7 8       0 3 6
        case('U'):
            if(direction == '+') {   //CW
                tmp.assign(BACK.begin(), BACK.end());
                BACK[6] = LEFT[8];
                BACK[7] = LEFT[5];
                BACK[8] = LEFT[2];
                LEFT[8] = FRONT[2];
                LEFT[5] = FRONT[1];
                LEFT[2] = FRONT[0];
                FRONT[2] = RIGHT[0];
                FRONT[1] = RIGHT[3];
                FRONT[0] = RIGHT[6];
                RIGHT[0] = tmp[6];
                RIGHT[3] = tmp[7];
                RIGHT[6] = tmp[8];
//CW
//
//  0 1 2       6 3 0
//  3 4 5   --> 7 4 1
//  6 7 8       8 5 2
//CCW
//
//  0 1 2       2 5 8
//  3 4 5   --> 1 4 7
//  6 7 8       0 3 6
                tmp.clear();
                std::vector<char>().swap(tmp);
                tmp.assign(UP.begin(), UP.end());
                UP[0] = tmp[6];
                UP[1] = tmp[3];
                UP[2] = tmp[0];
                UP[3] = tmp[7];
                UP[4] = tmp[4];
                UP[5] = tmp[1];
                UP[6] = tmp[8];
                UP[7] = tmp[5];
                UP[8] = tmp[2];

            }
            else {      //CCW
                tmp.assign(BACK.begin(), BACK.end());
                BACK[6] = RIGHT[0];
                BACK[7] = RIGHT[3];
                BACK[8] = RIGHT[6];
                RIGHT[0] = FRONT[2];
                RIGHT[3] = FRONT[1];
                RIGHT[6] = FRONT[0];
                FRONT[2] = LEFT[8];
                FRONT[1] = LEFT[5];
                FRONT[0] = LEFT[2];
                LEFT[8] = tmp[6];
                LEFT[5] = tmp[7];
                LEFT[2] = tmp[8];
                tmp.clear();
                std::vector<char>().swap(tmp);
                tmp.assign(UP.begin(), UP.end());
                UP[0] = tmp[2];
                UP[1] = tmp[5];
                UP[2] = tmp[8];
                UP[3] = tmp[1];
                UP[4] = tmp[4];
                UP[5] = tmp[7];
                UP[6] = tmp[0];
                UP[7] = tmp[3];
                UP[8] = tmp[6];
            }
        break;


        case('R'):
            if(direction == '+') {   //CW
                tmp.assign(BACK.begin(), BACK.end());
                BACK[8] = UP[8];
                BACK[5] = UP[5];
                BACK[2] = UP[2];
                UP[8] = FRONT[8];
                UP[5] = FRONT[5];
                UP[2] = FRONT[2];
                FRONT[8] = DOWN[0];
                FRONT[5] = DOWN[3];
                FRONT[2] = DOWN[6];
                DOWN[0] = tmp[8];
                DOWN[3] = tmp[5];
                DOWN[6] = tmp[2];
                tmp.clear();
                std::vector<char>().swap(tmp);
                tmp.assign(RIGHT.begin(), RIGHT.end());
                RIGHT[0] = tmp[6];
                RIGHT[1] = tmp[3];
                RIGHT[2] = tmp[0];
                RIGHT[3] = tmp[7];
                RIGHT[4] = tmp[4];
                RIGHT[5] = tmp[1];
                RIGHT[6] = tmp[8];
                RIGHT[7] = tmp[5];
                RIGHT[8] = tmp[2];
            }
            else {      //CCW
                tmp.assign(BACK.begin(), BACK.end());
                BACK[8] = DOWN[0];
                BACK[5] = DOWN[3];
                BACK[2] = DOWN[6];
                DOWN[0] = FRONT[8];
                DOWN[3] = FRONT[5];
                DOWN[6] = FRONT[2];
                FRONT[8] = UP[8];
                FRONT[5] = UP[5];
                FRONT[2] = UP[2];
                UP[8] = tmp[8];
                UP[5] = tmp[5];
                UP[2] = tmp[2];
                tmp.clear();
                std::vector<char>().swap(tmp);
                tmp.assign(RIGHT.begin(), RIGHT.end());
                RIGHT[0] = tmp[2];
                RIGHT[1] = tmp[5];
                RIGHT[2] = tmp[8];
                RIGHT[3] = tmp[1];
                RIGHT[4] = tmp[4];
                RIGHT[5] = tmp[7];
                RIGHT[6] = tmp[0];
                RIGHT[7] = tmp[3];
                RIGHT[8] = tmp[6];
            }
        break;
        case('D'):
            if(direction == '+') {   //CW
                tmp.assign(BACK.begin(), BACK.end());
                BACK[2] = RIGHT[8];
                BACK[1] = RIGHT[5];
                BACK[0] = RIGHT[2];
                RIGHT[8] = FRONT[6];
                RIGHT[5] = FRONT[7];
                RIGHT[2] = FRONT[8];
                FRONT[6] = LEFT[0];
                FRONT[7] = LEFT[3];
                FRONT[8] = LEFT[6];
                LEFT[0] = tmp[2];
                LEFT[3] = tmp[1];
                LEFT[6] = tmp[0];
                tmp.clear();
                std::vector<char>().swap(tmp);
                tmp.assign(DOWN.begin(), DOWN.end());
                DOWN[0] = tmp[6];
                DOWN[1] = tmp[3];
                DOWN[2] = tmp[0];
                DOWN[3] = tmp[7];
                DOWN[4] = tmp[4];
                DOWN[5] = tmp[1];
                DOWN[6] = tmp[8];
                DOWN[7] = tmp[5];
                DOWN[8] = tmp[2];
            }
            else {      //CCW
                tmp.assign(BACK.begin(), BACK.end());
                BACK[2] = LEFT[0];
                BACK[1] = LEFT[3];
                BACK[0] = LEFT[6];
                LEFT[0] = FRONT[6];
                LEFT[3] = FRONT[7];
                LEFT[6] = FRONT[8];
                FRONT[6] = RIGHT[8];
                FRONT[7] = RIGHT[5];
                FRONT[8] = RIGHT[2];
                RIGHT[8] = tmp[2];
                RIGHT[5] = tmp[1];
                RIGHT[2] = tmp[0];
                tmp.clear();
                std::vector<char>().swap(tmp);
                tmp.assign(DOWN.begin(), DOWN.end());
                DOWN[0] = tmp[2];
                DOWN[1] = tmp[5];
                DOWN[2] = tmp[8];
                DOWN[3] = tmp[1];
                DOWN[4] = tmp[4];
                DOWN[5] = tmp[7];
                DOWN[6] = tmp[0];
                DOWN[7] = tmp[3];
                DOWN[8] = tmp[6];
            }
        break;
        case('B'):
            if(direction == '+') {   //CW
                tmp.assign(DOWN.begin(), DOWN.end());
                DOWN[2] = LEFT[2];
                DOWN[1] = LEFT[1];
                DOWN[0] = LEFT[0];
                LEFT[2] = UP[2];
                LEFT[1] = UP[1];
                LEFT[0] = UP[0];
                UP[2] = RIGHT[2];
                UP[1] = RIGHT[1];
                UP[0] = RIGHT[0];
                RIGHT[2] = tmp[2];
                RIGHT[1] = tmp[1];
                RIGHT[0] = tmp[0];
                tmp.clear();
                std::vector<char>().swap(tmp);
                tmp.assign(BACK.begin(), BACK.end());
                BACK[0] = tmp[6];
                BACK[1] = tmp[3];
                BACK[2] = tmp[0];
                BACK[3] = tmp[7];
                BACK[4] = tmp[4];
                BACK[5] = tmp[1];
                BACK[6] = tmp[8];
                BACK[7] = tmp[5];
                BACK[8] = tmp[2];
            }
            else {      //CCW
            tmp.assign(DOWN.begin(), DOWN.end());
                DOWN[2] = RIGHT[2];
                DOWN[1] = RIGHT[1];
                DOWN[0] = RIGHT[0];
                RIGHT[2] = UP[2];
                RIGHT[1] = UP[1];
                RIGHT[0] = UP[0];
                UP[2] = LEFT[2];
                UP[1] = LEFT[1];
                UP[0] = LEFT[0];
                LEFT[2] = tmp[2];
                LEFT[1] = tmp[1];
                LEFT[0] = tmp[0];
                tmp.clear();
                std::vector<char>().swap(tmp);
                tmp.assign(BACK.begin(), BACK.end());
                BACK[0] = tmp[2];
                BACK[1] = tmp[5];
                BACK[2] = tmp[8];
                BACK[3] = tmp[1];
                BACK[4] = tmp[4];
                BACK[5] = tmp[7];
                BACK[6] = tmp[0];
                BACK[7] = tmp[3];
                BACK[8] = tmp[6];
            }
        break;
        case('F'):
            if(direction == '+') {   //CW
                tmp.assign(UP.begin(), UP.end());
                UP[6] = LEFT[6];
                UP[7] = LEFT[7];
                UP[8] = LEFT[8];
                LEFT[6] = DOWN[6];
                LEFT[7] = DOWN[7];
                LEFT[8] = DOWN[8];
                DOWN[6] = RIGHT[6];
                DOWN[7] = RIGHT[7];
                DOWN[8] = RIGHT[8];
                RIGHT[6] = tmp[6];
                RIGHT[7] = tmp[7];
                RIGHT[8] = tmp[8];
                tmp.clear();
                std::vector<char>().swap(tmp);
                tmp.assign(FRONT.begin(), FRONT.end());
                FRONT[0] = tmp[6];
                FRONT[1] = tmp[3];
                FRONT[2] = tmp[0];
                FRONT[3] = tmp[7];
                FRONT[4] = tmp[4];
                FRONT[5] = tmp[1];
                FRONT[6] = tmp[8];
                FRONT[7] = tmp[5];
                FRONT[8] = tmp[2];
            }
            else {      //CCW
                tmp.assign(UP.begin(), UP.end());
                UP[6] = RIGHT[6];
                UP[7] = RIGHT[7];
                UP[8] = RIGHT[8];
                RIGHT[6] = DOWN[6];
                RIGHT[7] = DOWN[7];
                RIGHT[8] = DOWN[8];
                DOWN[6] = LEFT[6];
                DOWN[7] = LEFT[7];
                DOWN[8] = LEFT[8];
                LEFT[6] = tmp[6];
                LEFT[7] = tmp[7];
                LEFT[8] = tmp[8];
                tmp.clear();
                std::vector<char>().swap(tmp);
                tmp.assign(FRONT.begin(), FRONT.end());
                FRONT[0] = tmp[2];
                FRONT[1] = tmp[5];
                FRONT[2] = tmp[8];
                FRONT[3] = tmp[1];
                FRONT[4] = tmp[4];
                FRONT[5] = tmp[7];
                FRONT[6] = tmp[0];
                FRONT[7] = tmp[3];
                FRONT[8] = tmp[6];
            }
        break;
    }

}

void PrintUP() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            std::cout << UP[3*i+j];
        }
        std::cout << '\n';
    }
}



////////////////////////////////



int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Input();

    return 0;
}