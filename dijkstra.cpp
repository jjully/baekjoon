#include<iostream>
#include<vector>
#include<queue>

int number = 6;
int INF = 10000000;

std::vector< std::pair<int, int> > a[7];
int d[7];



void dijkstra(int start);

int main()
{
    for(int i=0; i<=number; i++) {
        d[i] = INF;
    }

    a[1].push_back(std::make_pair(2, 2));   //[n]: criteria node //first: connected node, second: distance
    a[1].push_back(std::make_pair(3, 5));   //ex. node 1 is connected to 2, 3, 4 with distance 2, 5, 1 each
    a[1].push_back(std::make_pair(4, 1));

    a[2].push_back(std::make_pair(1, 2));
    a[2].push_back(std::make_pair(3, 3));
    a[2].push_back(std::make_pair(4, 2));

    a[3].push_back(std::make_pair(1, 5));
    a[3].push_back(std::make_pair(2, 3));
    a[3].push_back(std::make_pair(4, 3));    
    a[3].push_back(std::make_pair(5, 1));
    a[3].push_back(std::make_pair(6, 5));


    a[4].push_back(std::make_pair(1, 1));
    a[4].push_back(std::make_pair(2, 2));
    a[4].push_back(std::make_pair(3, 3));
    a[4].push_back(std::make_pair(5, 1));

    a[5].push_back(std::make_pair(3, 1));
    a[5].push_back(std::make_pair(4, 1));
    a[5].push_back(std::make_pair(6, 2));

    a[6].push_back(std::make_pair(3, 5));
    a[6].push_back(std::make_pair(5, 2));

    dijkstra(1);

    for(int i=1;i<=number;i++) {
        std::cout << d[i];
    }


    return 0;
}

void dijkstra(int start) {
    d[start] = 0;
    std::priority_queue<std::pair<int, int> > pq;
    pq.push(std::make_pair(start, 0));  //distance 0 with myself

    while(!pq.empty()) {
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();

        if(d[current] < distance) continue;
        for(int i=0; i<a[current].size(); i++) {
            int next = a[current][i].first;
            int nextDistance = distance + a[current][i].second;

            if(nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push(std::make_pair(next, -nextDistance));
            }
        }
    }
}