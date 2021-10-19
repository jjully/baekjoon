//baeakjoon
//15686
//find shortest -> use house/chicken_house v and find min
//combination
//use dp to make time shorter

//nCM * house_size * M -> this way
//house_size*chicken_house_size + nCM 

#include<iostream>
#include<vector>
#include<cmath>

int N=0, M=0, city_d = 250000;
std::vector<int> V;
std::vector<std::pair<int, int> > house;
std::vector<std::pair<int, int> > chicken_house;    // (row, col)
std::vector<std::vector<int> > chicken_d;
std::vector<bool> cur_chicken_house;

//fcns
void solution();
void FindCityD();
void combination(int cnt, int idx);
inline int sub(int a, int b);

int main() {

    //0. Input
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;

    int temp=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            std::cin >> temp;
            if(temp == 1) { house.push_back({i, j}); }
            else if(temp == 2) { chicken_house.push_back({i, j}); }
        }
    }

    solution();

    return 0;
}

//nCM * house_size * M
//house_size*chicken_house_size + nCM -> this way

void solution() {


    //0. check chicken_d first
    //std::vector<std::vector<int> > chicken_d;   //chicken_d[i][j] == distance from house[i] to chicken_house[j]
    chicken_d.resize(house.size()); //for all house
    for(int i=0; i<house.size(); i++) {
        chicken_d[i].resize(chicken_house.size(), 0);
    }

    //calculate all chicken_d first
    for(int i=0; i<house.size(); i++) {
        int houseR = house[i].first, houseC = house[i].second;
        for(int j=0; j<chicken_house.size(); j++) {
            int chickenR = chicken_house[j].first, chickenC = chicken_house[j].second;
            chicken_d[i][j] = abs(houseR-chickenR) + abs(houseC-chickenC);
        }
    }

    //1. if ( M == chicken_house.size() ) go to BFS to add all distance
    //2. else: combination of chickenhouse -> find minimum city_distance(find min)
    cur_chicken_house.resize(chicken_house.size(), false);
    int chicken_house_size = chicken_house.size();

    if( M == chicken_house_size ) {
        for(int i=0; i<M; i++) {
            V.push_back(i);
        }
        FindCityD();
    }
    else {
        combination(0, 0);
    }

    std::cout << city_d;
}


void FindCityD() {

    int temp_city_d=0;
    int house_size=chicken_d.size();
    for(int i=0; i<house_size; i++) {   //for all house
        int temp_ch_d = 2*N;
        for(int j=0; j<M; j++) {
            if( chicken_d[i][V[j]] < temp_ch_d ) {
                temp_ch_d = chicken_d[i][V[j]];
            }
        }
        //add to city_d
        temp_city_d += temp_ch_d;
    }
    if(temp_city_d < city_d) city_d = temp_city_d;
}

void combination(int cnt, int idx) {

    if(cnt == M) {
        int temp_city_d=100*13;
        FindCityD();
        if(temp_city_d < city_d) city_d = temp_city_d;
        return;
    }

    for(int i=idx; i<cur_chicken_house.size(); i++) {
        if(cur_chicken_house[i] == true) continue;
        cur_chicken_house[i] = true;
        V.push_back(i);
        combination(cnt+1, idx+1);
        cur_chicken_house[i] = false;
        V.pop_back();
    }

}


inline int sub(int a, int b) {
    if (a>b) return a-b;
    else return b-a;
}