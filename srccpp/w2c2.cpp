
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
    int prev = -1;
    unordered_map<int, double> edges;

    bool operator<(const Node &other) const{
        return time > other.time;
    }
};



int main(){

    // cin >> numCases;

    // for(int test = 0; test < numCases; test++){

        //get number of nodes, edges
        cin >> n;
        cin >> m;

        //make data structures
        priority_queue<Node> que;
        vector<Node> nodes;
        bool visited[n];

        //make node vector
        for(int i = 0; i < n; i++){
            double mdist = 0;
            if(i != 0){
                mdist = __DBL_MAX__;
            }
            Node* nod = new Node({i, mdist});
            visited[i] = false;
            nodes.push_back(*nod);
        }
        
        //put edges onto nodes
        for(int i = 0; i < m; i++){
            int f, t;       //from to
            double tim;    //speed length
            cin >> f;
            cin >> t;
            cin >> tim;
            //if theres no edge or this edge is quicker
            if(nodes[f-1].edges.find(t-1) == nodes[f-1].edges.end() ||  nodes[f-1].edges[t-1] > tim){
                //assign the time to get there
                nodes[f-1].edges[t-1] = tim;
            }
            if(nodes[t-1].edges.find(f-1) == nodes[t-1].edges.end() ||  nodes[t-1].edges[f-1] > tim){
                //assign the time to get there
                nodes[t-1].edges[f-1] = tim;
            }
        }

        //put the starting node on the queue
        que.push(nodes[0]);


        //dajigastra algo
        while(!que.empty()){
            struct Node node = que.top();
            que.pop();
            if(visited[node.id]) continue;
            if(node.id == n-1)break;
            visited[node.id] = true;
            for(auto ed  = node.edges.begin(); ed != node.edges.end(); ed++){
                double alt = node.time + node.edges[ed->first];
                if(alt < nodes[ed->first].time){
                    nodes[ed->first].time = alt;
                    nodes[ed->first].prev = node.id;
                    que.push(nodes[ed->first]);
                    
                }
            }

        }
        Node cur = nodes[nodes.size()-1];
        if(cur.prev == -1){
            cout << "-1" << endl;
            return 0;
        }
        stack<int> path;
        path.push(nodes.size()-1);
        while(cur.prev != -1){
            path.push(cur.prev);
            cur = nodes[cur.prev];
        }
        while(!path.empty()){
            cout << (path.top()+1) << " ";
            path.pop();
        }

        // //print time to get to the last node
        // double answer = nodes[nodes.size()-1].time;
        // if(answer == __DBL_MAX__){
        //     cout << "Error: Could not find a path";
        // }else{
        //     cout << ((int)round(answer)) << endl;
        // }

    // }//end test loop

}
