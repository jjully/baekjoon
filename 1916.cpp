#include<iostream>
#include<vector>
#include<queue>

#define INF 100000000

void dijkstra(int d[], int city, int departure,  std::vector<std::pair<int64_t, int> > *busInfo);

int main()
{
    int city=0, bus=0;
    std::cin >> city >> bus;

    int d[city+1];

    for(int i=1; i<=city; i++) { d[i] = INF; }

    std::vector<std::pair<int64_t, int> > busInfo[city+1];   //ex. busInfo[0] = (1, 2) : from city0 to city1, cost 2

    int city_buf=0, dest_buf=0;
    int64_t cost_buf=0;
    for(int i=1; i<=bus; i++) {
        std::cin >> city_buf >> dest_buf >> cost_buf;
        busInfo[city_buf].push_back(std::make_pair(cost_buf, dest_buf));
    }

    int departure=0, arrival=0;
    std::cin >> departure >> arrival;

    dijkstra(d, city, departure, busInfo);

    std::cout << d[arrival];

    return 0;
}

void dijkstra(int d[], int city, int departure,  std::vector<std::pair<int64_t, int> > *busInfo) {

    std::priority_queue<std::pair<int64_t, int> > pq;
    d[departure] = 0;
    pq.push(std::make_pair(0, departure));

    while(!pq.empty()) {

        int current = pq.top().second;   //city now im located
        int64_t distance = -pq.top().first; //distance from departure to the current city
        pq.pop();


        if(d[current] < distance) continue;
        for(int i=0; i<busInfo[current].size(); i++) {
            int next = busInfo[current][i].second;
            int nextDistance = distance + busInfo[current][i].first;

            if(nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push(std::make_pair(-nextDistance, next));
            }
        }
    }
}