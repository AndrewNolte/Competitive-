
#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>

using namespace std;

int m;
int n;
int numCases;

struct Node{
    int id;
    double time;
    unordered_map<int, double> edges;

    bool operator<(const Node &other) const{
        return time > other.time;
    }
};



int main(){

    cin >> numCases;

    for(int test = 0; test < numCases; test++){

        //get number of nodes, edges
        cin >> n;
        cin >> m;

        //make data structures
        priority_queue<Node> que;
        vector<Node> nodes;
        bool visited[n];

        //make node vector
        for(int i = 0; i < n; i++){
            double mdist = __DBL_MAX__;
            Node* nod = new Node({i, mdist});
            visited[i] = false;
            nodes.push_back(*nod);
        }
        
        //put edges onto nodes
        for(int i = 0; i < m; i++){
            int f, t;       //from to
            double v, d;    //velocity distance
            cin >> f;
            cin >> t;
            cin >> v;
            cin >> d;
            double tim = d/v; 
            //if theres no edge or this edge is quicker, assign time
            if(nodes[f-1].edges.find(t-1) == nodes[f-1].edges.end() ||  nodes[f-1].edges[t-1] > tim){
                nodes[f-1].edges[t-1] = tim;
            }
        }

        //put the starting node on the queue
        nodes[0].time = 0;
        que.push(nodes[0]);

        //dajigastra algo
        while(!que.empty()){
            //top pop and check
            struct Node node = que.top();
            que.pop();
            if(visited[node.id]) continue;
            if(node.id == n-1) break;
            visited[node.id] = true;
            //go through neighbors
            for(auto ed  = node.edges.begin(); ed != node.edges.end(); ed++){
                //computer time if going through this node
                double alt = node.time + node.edges[ed->first];
                //if its better, replace it
                if(alt < nodes[ed->first].time){
                    nodes[ed->first].time = alt;
                    //nodes are pass by value into the queue, so we have to push it again
                    que.push(nodes[ed->first]);
                }
            }
        }

        //print the time to get to last node
        double answer = nodes[nodes.size()-1].time;
        if(answer == __DBL_MAX__){
            cout << "Error: Could not find a path";
        }else{
            cout << ((int)round(answer)) << endl;
        }

    }//end test loop

}//end main
