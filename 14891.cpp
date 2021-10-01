//baekjoon 14891
//simulation
/*
#include<iostream>
#include<vector>
#include<string>

enum {LEFT = 6, RIGHT = 2, CW=1, CCW=-1};
int K=0;

//fcns
void v2DInit(std::vector<std::vector<int> >& v, int row, int col, int val);
bool GoRight(int& idx);
bool GoLeft(int& idx);
void Move(std::vector<std::string>& wheel, int cWheel, int cDirec);
void ccw(std::vector<std::string>& wheel, int cWheel);
void cw(std::vector<std::string>& wheel, int cWheel);
void ChangeDirec(int& cDirec);
void solution(std::vector<std::string>& wheel, std::vector<std::pair<int, int> >& moving, int& score);



void v2DInit(std::vector<std::vector<int> >& v, int row, int col, int val) {
  v.resize(row);
  for(int i=0; i<row; i++)
    v[i].resize(col, val);
}

bool GoRight(int& idx) {
    if(idx == 3)
      return false;
    else {
      idx++;
      return true;
    }
}

bool GoLeft(int& idx) {
    if(idx == 0)
      return false;
    else {
      idx--;
      return true;
    }
}

void Move(std::vector<std::string>& wheel, int cWheel, int cDirec) {
  //std::string str = wheel[cWheel];
  switch(cDirec) {
    case(CW):
      cw(wheel, cWheel);
      break;
    case(CCW):
      ccw(wheel, cWheel);
      break; 
  }
}

void ccw(std::vector<std::string>& wheel, int cWheel) {
  char tmp = wheel[cWheel][0];
  for(int idx=0; idx<7; idx++) {
    int nextIdx = (idx+1)%8;
    wheel[cWheel][idx] = wheel[cWheel][nextIdx];
  }
  wheel[cWheel][7] = tmp;
}

void cw(std::vector<std::string>& wheel, int cWheel) {
  char tmp = wheel[cWheel][7];
  for(int idx=7; idx>0; idx--) {
    int nextIdx = (idx+7)%8;
    wheel[cWheel][idx] = wheel[cWheel][nextIdx];
  }
  wheel[cWheel][0] = tmp;
}

void ChangeDirec(int& cDirec) {
  if(cDirec == CW)
    cDirec = CCW;
  else
    cDirec = CW;
}

void solution(std::vector<std::string>& wheel, std::vector<std::pair<int, int> >& moving, int& score) {

  //std::vector<bool> flag(4, false);
  for(int i=0; i<K; i++) {

    //reset flag
    //for(int j=0; j<4; j++)
      //flag[j] = false;
    
    //check this move
    int cWheel = moving[i].first-1;
    int cDirec = moving[i].second;
    
    //first, move
    char Rpolar = wheel[cWheel][RIGHT];
    char Lpolar = wheel[cWheel][LEFT];
    Move(wheel, cWheel, cDirec);

    //int idx=cWheel;
    //오른쪽으로 끝까지 진행
    //왼쪽으로 끝까지 진행 후 끝내기

    //오른쪽 움직임
    int idx=cWheel;
    int direc=cDirec;
    while(1) {
      
      if(GoRight(idx) == false) break;
      if(Rpolar != wheel[idx][LEFT]) {
        Rpolar = wheel[idx][RIGHT];
        ChangeDirec(direc);
        Move(wheel, idx, direc);
      }
      else { break; }
    }

    idx = cWheel;
    direc = cDirec;
    while(1) {

      if(GoLeft(idx) == false) break;
      if(Lpolar != wheel[idx][RIGHT]) {
        Lpolar = wheel[idx][LEFT];
        ChangeDirec(direc);
        Move(wheel, idx, direc);
      }
      else { break; }
    }
  }

  if(wheel[0][0] == '1') score+=1;
  if(wheel[1][0] == '1') score+=2;
  if(wheel[2][0] == '1') score+=4;
  if(wheel[3][0] == '1') score+=8;

}

int main() {

  std::vector<std::string> wheel(4);
  //v2DInit(wheel, 4, 8, 0);

  for(int i=0; i<4; i++) {
    std::cin >> wheel[i];
  }


  std::cin >> K;
  std::vector<std::pair<int, int> > moving(K);
  for(int i=0; i<K; i++) {
    //int temp_first=0, temp_second=0;
    //std::cin >> temp_first >> temp_second;
    std::cin >> moving[i].first >> moving[i].second;  //first: wheel no. // second: 1 - cw, -1: ccw
  }

  int score=0;
  solution(wheel, moving, score);
  std::cout << score;

  return 0;
}
*/