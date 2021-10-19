//baeakjoon
//15686
//find shortest -> use house/chicken_house v and find min
//combination
//use dp to make time shorter

#include<iostream>
#include<vector>

int N=0, M=0;
std::vector<int> V;

//fcns
void solution(std::vector<std::pair<int, int> >& house, std::vector<std::pair<int, int> >& chicken_house, int& city_d);
void FindCityD(std::vector<std::vector<int> >& chicken_d, std::vector<bool>& cur_chicken_house, int& city_d);
void combination(std::vector<std::vector<int> >& chicken_d, std::vector<bool>& cur_chicken_house, int& city_d, int cnt, int idx);
inline int sub(int a, int b);

int main() {

    //0. Input
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;

    std::vector<std::pair<int, int> > house;
    std::vector<std::pair<int, int> > chicken_house;    // (row, col)
    int temp=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            std::cin >> temp;
            if(temp == 1) { house.push_back({i, j}); }
            else if(temp == 2) { chicken_house.push_back({i, j}); }
        }
    }
    int city_d = 100*13;
    solution(house, chicken_house, city_d);
    std::cout << city_d;

    return 0;
}

void solution(std::vector<std::pair<int, int> >& house,
                std::vector<std::pair<int, int> >& chicken_house, int& city_d) {


    //0. check chicken_d first
    std::vector<std::vector<int> > chicken_d;   //chicken_d[i][j] == distance from house[i] to chicken_house[j]
    chicken_d.resize(house.size()); //for all house
    for(int i=0; i<house.size(); i++) {
        chicken_d[i].resize(chicken_house.size(), 0);
    }

    //calculate all chicken_d first
    for(int i=0; i<house.size(); i++) {
        int houseR = house[i].first, houseC = house[i].second;
        for(int j=0; j<chicken_house.size(); j++) {
            int chickenR = chicken_house[j].first, chickenC = chicken_house[j].second;
            chicken_d[i][j] = sub(houseR, chickenR) + sub(houseC, chickenC);
        }
    }

    //1. if ( M == chicken_house.size() ) go to BFS to add all distance
    //2. else: combination of chickenhouse -> find minimum city_distance(find min)
    std::vector<bool> cur_chicken_house(chicken_house.size(), false);
    int chicken_house_size = chicken_house.size();

    if( M == chicken_house_size ) {
        for(int i=0; i<M; i++) {
            cur_chicken_house[i] = true;
        }
        FindCityD(chicken_d, cur_chicken_house, city_d);
    }
    else {
        combination(chicken_d, cur_chicken_house, city_d, 0, 0);
    }

}


void FindCityD(std::vector<std::vector<int> >& chicken_d, std::vector<bool>& cur_chicken_house, int& city_d) {

    int temp_city_d=0;
    int house_size=chicken_d.size();
    for(int i=0; i<house_size; i++) {   //for all house
        int temp_ch_d = 2*N;
        for(int j=0; j<cur_chicken_house.size(); j++) {
            if( cur_chicken_house[j] == true && chicken_d[i][j] < temp_ch_d ) {
                temp_ch_d = chicken_d[i][j];
            }
        }
        //add to city_d
        temp_city_d += temp_ch_d;
    }
    if(temp_city_d < city_d) city_d = temp_city_d;
}

void combination(std::vector<std::vector<int> >& chicken_d, std::vector<bool>& cur_chicken_house, int& city_d, int cnt, int idx) {

    if(cnt == M) {
        int temp_city_d=100*13;
        FindCityD(chicken_d, cur_chicken_house, temp_city_d);
        if(temp_city_d < city_d) city_d = temp_city_d;
        return;
    }

    for(int i=idx; i<cur_chicken_house.size(); i++) {
        if(cur_chicken_house[i] == true) continue;
        cur_chicken_house[i] = true;
        combination(chicken_d, cur_chicken_house, city_d, cnt+1, i+1);
        cur_chicken_house[i] = false;
    }

}


inline int sub(int a, int b) {
    if (a>b) return a-b;
    else return b-a;
}