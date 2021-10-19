//baeakjoon
//15686
//find shortest -> use house/chicken_house v and find min
//combination

#include<iostream>
#include<vector>

int N=0, M=0;

//fcns
void solution(std::vector<std::pair<int, int> >& house, std::vector<std::pair<int, int> >& chicken_house, int& city_d);
void FindCityD(std::vector<std::pair<int, int> >& house, std::vector<std::pair<int, int> >& chicken_house, int& city_d);
void combination(std::vector<std::pair<int, int> >& house, std::vector<std::pair<int, int> >& chicken_house, std::vector<std::pair<int, int> >& cur_chicken_house, int& city_d, int cnt, int idx);
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
            if(temp == 2) { chicken_house.push_back({i, j}); }
        }
    }
    int city_d = 100*13;
    solution(house, chicken_house, city_d);
    std::cout << city_d;

    return 0;
}

void solution(std::vector<std::pair<int, int> >& house,
                std::vector<std::pair<int, int> >& chicken_house, int& city_d) {

    //1. if ( M == chicken_house.size() ) go to BFS to add all distance
    //2. else: combination of chickenhouse -> find minimum city_distance(find min)
    if( M == chicken_house.size() ) FindCityD(house, chicken_house, city_d);
    else {
        std::vector<std::pair<int, int> > cur_chicken_house;
        combination(house, chicken_house, cur_chicken_house, city_d, 0, 0);
    }

}


void FindCityD(std::vector<std::pair<int, int> >& house, std::vector<std::pair<int, int> >& chicken_house, int& city_d) {

    int temp_city_d=0;
    int house_size=house.size();
    for(int i=0; i<house_size; i++) {   //for all house
        int chicken_d=2*N, chickenhouse_size=chicken_house.size();
        int house_r = house[i].first, house_c = house[i].second;
        for(int j=0; j<chickenhouse_size; j++) {    //check chicken_d
            int ch_house_r = chicken_house[j].first, ch_house_c = chicken_house[j].second;
            int temp_d = sub(house_r, ch_house_r) + sub(house_c, ch_house_c);
            if(temp_d < chicken_d) chicken_d = temp_d;
        }
        //add to city_d
        temp_city_d += chicken_d;
    }
    if(temp_city_d < city_d) city_d = temp_city_d;
}

void combination(std::vector<std::pair<int, int> >& house, std::vector<std::pair<int, int> >& chicken_house, std::vector<std::pair<int, int> >& cur_chicken_house, int& city_d, int cnt, int idx) {

    if(cnt == M) {
        int temp_city_d=100*13;
        FindCityD(house, cur_chicken_house, temp_city_d);
        if(temp_city_d < city_d) city_d = temp_city_d;
        return;
    }

    for(int i=idx; i<chicken_house.size(); i++) {
        cur_chicken_house.push_back(chicken_house[i]);
        combination(house, chicken_house, cur_chicken_house, city_d, cnt+1, idx+1);
        cur_chicken_house.pop_back();
    }

}


inline int sub(int a, int b) {
    if (a>b) return a-b;
    else return b-a;
}