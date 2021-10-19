//baeakjoon
//15686
//find shortest -> use house/chicken_house v and find min
//combination

//nCM * house_size * M -> this way
//house_size*chicken_house_size + nCM 

//solved!!
//문제는 당연히 combination에 있었음(brute force 문제이므로 시간 초과가 발생하면 당연히 이 부분이 문제일 확률이 높음)
//idx를 넘겨줄 때 i+1로 해주어야 뒤부터 보는데 idx로 넘겨주니까 그냥 봤던 곳부터 또 보고, 또 보고 해서 그냥 0부터 10까지, 1부터 10까지, 2부터 10까지 이런 식으로 반복해서 봐버림
//따라서 nCr보다 훨씬 큰 값이 되어버림
//앞 버젼들도 idx만 i로 바꿔주면 풀 수 있음
//전역변수를 적절히 사용하는 것이 훨씬 깔끔함

#include<iostream>
#include<vector>
#include<cmath>

int N=0, M=0, city_d = 250000, chicken_house_size=0;
std::vector<std::pair<int, int> > V;
std::vector<std::pair<int, int> > house;
std::vector<std::pair<int, int> > chicken_house;    // (row, col)
bool cur_chicken_house[13];

//fcns
void solution();
int FindCityD();
void combination(int cnt, int idx);

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

    chicken_house_size = chicken_house.size();
    solution();

    return 0;
}

//nCM * house_size * M -> this way
//house_size*chicken_house_size + nCM 

void solution() {

    //1. if ( M == chicken_house.size() ) go to BFS to add all distance
    //2. else: combination of chickenhouse -> find minimum city_distance(find min)
    //cur_chicken_house.resize(chicken_house.size(), false);

    combination(0, 0);
    std::cout << city_d;
}


int FindCityD() {

    int sum=0;
    for(int i=0; i<house.size(); i++) {   //for all house
        int d = 2*N;
        int hr = house[i].first, hc = house[i].second;

        for(int j=0; j<V.size(); j++) {
            int cr = V[j].first, cc = V[j].second;
            int dist = abs(hr - cr) + abs(hc - cc);
            d = (d < dist) ? d : dist;
        }
        //add to city_d
        sum += d;
    }
    return sum;
}

void combination(int cnt, int idx) {

    if(cnt == M) {
        int tmp = FindCityD();
        city_d = (city_d <tmp) ? city_d:tmp;
        return;
    }

    for(int i=idx; i<chicken_house_size; i++) {
        if(cur_chicken_house[i] == true) continue;
        cur_chicken_house[i] = true;
        V.push_back(chicken_house[i]);
        combination(cnt+1, i);
        cur_chicken_house[i] = false;
        V.pop_back();
    }

}