#include<iostream>
#include<queue>
#include<vector>
#include<map>
//#include<cstdint>
//#include<cinttypes>

//using namespace std;

//typedef std::pair <int, int> Intpair;


class Node {
    public:
        int v1;
        int v2;
        int weight;
    Node(int a, int b, int c) {
        this->v1 = a;
        this->v2 = b;
        this->weight = c;
    }
};

class cmp {
    public:
    bool operator() (Node &a, Node& b) {
        return a.weight > b.weight;
    }
};



int getRoot(std::vector<int>&parent, int x) {
    if(parent[x-1] == x) { return x; }
    else { return getRoot(parent, parent[x-1]); }
}

int main(){

    int V=0, E=0;
    std::cin >> V >> E;
    //int visit[V];

    //for(int i=0; i<V; i++) { visit[i] = 0; }    //for no cycle
    
    /////////////////////////////////

    //     NEED TO CHECK CYCLE     //

    /////////////////////////////////


    std::priority_queue<Node, std::vector<Node>, cmp > weightInfo;
    //std::priority_queue<std::pair<int, std::pair<int, int> > > weightInfo;  // ( -weight, (v1, v2) )
    //std::map<int, int> vertexInfo[V+1];
    std::vector<int> parent;

    for(int i=1; i<=10000; i++) {
        //vertexInfo[i].insert( Intpair(i, i) );     //init vertexInfo
        parent.push_back(i);            //waste parent[0]
    }

    int v1_buf=0, v2_buf=0, w_buf=0;
    for(int i=0; i<E; i++) {
        std::cin >> v1_buf >> v2_buf >> w_buf;
        weightInfo.push( Node(v1_buf, v2_buf, w_buf) );  //push all edge-weight info
    }

    int count = 0;
    int64_t ans = 0;
    while( !weightInfo.empty() ) {

        int weight = weightInfo.top().weight;   //the edge with the smallest weight
        int v1 = weightInfo.top().v1;
        int v2 = weightInfo.top().v2;
        weightInfo.pop();

        int v1root = getRoot(parent, v1);
        int v2root = getRoot(parent, v2);
        if( v1root == v2root ) continue;    // if this edge makes cycle, continue
        else {
            count++;
            ans += weight;
            if( v1root > v2root ) {
                //vertexInfo[v1].insert();
                parent[v1root-1] = v2root;
            }
            else { 
                parent[v2root-1] = v1root;
            }
        }
        if( count == (V-1) ) { break; }       //if all vertex are visited, break
    }

    std::cout << ans;

    return 0;
}