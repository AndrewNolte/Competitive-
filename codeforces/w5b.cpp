
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

bool canGoTo(pair<int,int> ab, pair<int,int> cd){
    return (cd.first < ab.first && ab.first < cd.second) || (cd.first < ab.second && ab.second < cd.second);
}


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
        for(int i = 0; i <= 2*n; i++){
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
    int numq;
    cin >> numq;

    int numIntervals = 0;
    Graph graph(numq);
    
    // vector<set<int>> list;
    // vector<set<int>> fromList;

    vector<pair<int,int>> intervals;

    for(int query = 0; query < numq; query++){
        int type, a, b;
        cin >> type;
        cin >> a;
        cin >> b;


        if(type == 1){
            pair<int,int> mypair = {a,b};
            // set<int> myList;
            // set<int> myFromList;
            // myList.insert(numIntervals);
            // myList.insert(numIntervals);
            //figure out which ones we can go to

            for(int i = 0; i < numIntervals; i++){
                if(canGoTo(mypair, intervals[i])){
                    graph.addEdge(numIntervals, i, 1);
                    // for(auto j = list[i].begin(); j != list[i].end(); j++){
                    //     //add the ones that those ^ can go to, to our list
                    //     myList.insert(*j);
                    //     //add to from
                    //     fromList[i].insert(numIntervals);
                    // }
                }
            }
            //figure out which ones can go to us, put us on their list
            for(int i = 0; i < numIntervals; i++){
                if(canGoTo(intervals[i], mypair)){
                    graph.addEdge(i, numIntervals, 1);
                    // for(auto j = myList.begin(); j != myList.end(); j++){
                    //      list[i].insert(*j);
                    //      myFromList.insert(i);
                    // }
                    // for(auto j = fromList[i].begin(); j != fromList[i].end(); j++){
                    //     if(*j == numIntervals) continue;
                    //     list[*j].insert(numIntervals);
                    //     myFromList.insert(*j);
                    // }
                }
            }
            
            //backpropo
            // for(int i = 0; i < numIntervals; i++){
            //     if(list[i].find(numIntervals) != list[i].end()){ //if it goes to us
            //         //its from will go to us
                    
            //     }
            // }
            // for(auto i = )
            // bool isDone = false;
            // while(!isDone){
            //     isDone = true;
            //     for(int i = 0; i < numIntervals; i++){
            //         //look through this one's gotos
            //         for(auto j = list[i].begin(); j != list[i].end(); j++){
            //             if((*j) == numIntervals){
            //                 isDone = false;
            //                 //copy over our shit
            //                 for(auto k = myList.begin(); k != myList.end(); k++){
            //                     list[i].insert(*k);
            //                 }
            //             }
            //         }   
            //     }
            // }
            
            //need to back propogate ughhh ... we'll do that at eval time
            // myList.insert()
            intervals.push_back(mypair);
            // list.push_back(myList);
            // fromList.push_back(myFromList);

            numIntervals++;

        }else{
            a--;
            b--;
            // if(list[a].find(b) != list[a].end() || fromList[b].find(a) != fromList[b].end()){
            if(graph.bellManFord(a)[b] != maxval){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }

            //test shit
            //just put us on their list
        }

    }
}