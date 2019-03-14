#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>
#include <set>

using namespace std;

const int maxval = 1e9;    //assign to unreachable stuff
const int minval = -1e9; //assign to infinite negative loops
class Edge{
    public:
    int cost;
    int from;
    int to;
    Edge(int f, int t, int c) : from(f), to(t), cost(c) {

    }
};
class Graph{
  public:
    int n;
    vector<Edge> edges;


    Graph(int n){
        this->n = n;
    }

    void addEdge(int f, int t, int c){
        Edge edge(f, t, c);
        edges.push_back(edge);
    }

    int* bellManFord(int start){
        int* cost = new int[n]; //cost array
        fill_n(cost, n, maxval);
        cost[start] = 0;
        for(int i = 0; i <= n; i++){
            //relax
            for(auto j = edges.begin(); j != edges.end(); j++){
                if ((cost[j->from] + j->cost) < cost[j->to]){
                    cost[j->to] = j->cost + cost[j->from];
                }
            }
        }
        //print
        // cout << "cost: " << " ";
        // for(int i = 0; i < n; i++){
        //     cout << cost[i] << " ";
        // }
        // cout << endl;
        //check for stuff that still goes down
        bool hasCycles = false;
        for(auto j = edges.begin(); j != edges.end(); j++){
            if (cost[j->from] + j->cost < cost[j->to]){
                hasCycles = true;
                break;
            }
        }
        // cout << hasCycles << endl;
        if(!hasCycles) return cost;



        //need to rerelax all edges to see which ones are infinite
        int* costActual = new int[n]; //cost array
        // copy(begin(cost), end(cost), begin(costActual));
        for(int i = 0; i < n; i++){
            costActual[i] = cost[i];
        }

        for(int i = 0; i <= n; i++){
            //relax
            for(auto j = edges.begin(); j != edges.end(); j++){
                if (cost[j->from] + j->cost < cost[j->to]){
                    cost[j->to] = j->cost + cost[j->from];
                    costActual[j->to] = minval;
                    costActual[j->from] = minval;
                }
            }
        }
        return costActual;
    }

};
int main(){
    int numCases;
    cin >> numCases;
    for (int test = 0; test < numCases; test++){
        int n, m, k;
        
        cin >> n;
        cin >> m;
        cin >> k;
        Graph graph(n);

        for(int i = 0; i < m; i++){
            int from, to, cost;
            cin >> from;
            cin >> to;
            cin >> cost;
            graph.addEdge(from-1, to-1, -cost); 
            //neg because algo wants to minimize

        }
        int* arr = graph.bellManFord(0);

        int ans = -1 * arr[n-1]; //negate again
        
        if(ans == minval){
            cout << "-1" << endl;
        }else if(ans == maxval){
            cout << "infinity" << endl;
        }else{
            cout << (ans + k) << endl;
        }




    }
}