#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>

#include <climits>

using namespace std;

class Graph
{
  public:
    int n;
    vector<set<int>> list;
    vector<int> degree;

    Graph(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            set<int> vec;
            list.push_back(vec);
            degree.push_back(0);
        }
    }

    void addEdge(int u, int v)
    {
        list[u].insert(v);
        list[v].insert(u);
        degree[v] = degree[v]+1;
        degree[u] = degree[u]+1;
    }
    // vector<int> dfs(int begin, int end)
    // {
    //     bool visited[n];
    //     stack<int> st;
    // }
    void removeEdge(int from, int to)
    {
        list[from].erase(list[from].find(to));
        list[to].erase(list[to].find(from));

    }
};

int main()
{
    int numCases;
    cin >> numCases;

    for (int test = 0; test < numCases; test++)
    {
        int n, m;
        cin >> n;
        cin >> m;
        Graph graph(n);

        for (int i = 0; i < m; i++)
        {
            int from, to;
            cin >> from;
            cin >> to;
            graph.addEdge(from - 1, to - 1); //adds double edge
        }
        //get start Nodes
        int v = -1;
        int endNode = -1;
        for (int i = 0; i < graph.degree.size(); i++){
            if (graph.degree[i] % 2 == 1){
                if (v == -1){
                    v = i;
                }else if (endNode == -1){
                    endNode = i;
                }else{
                    cout << "-1\n";
                    return 0;
                }
            }
        }
        if (v == -1){
            v = 0;
            endNode = 0;
        }else{
            graph.addEdge(v, endNode);
            
        }
        int startNode = v;

        //begin algorithm
        // vector<int> trail = graph.dfs(v, endNode);
        // for (int i = 0; i < trail.size() - 1; i++)
        // {
        //     graph.removeEdge(trail[i], trail[i + 1]);
        //     graph.removeEdge(trail[i + 1], trail[i]);
        // }
        
        vector<int> Circuit;
        stack<int> Stack;
        Stack.push(v);
        while(!Stack.empty()){
            // if(graph.list[v].size() == 1 && *graph.list[v].begin() == endNode){
            //     //nothing
            //     Circuit.push_back(v);
            //     v = Stack.top();
            //     Stack.pop();
            // }else 
            if(!graph.list[v].empty()){//if the current node has edges
                //put it onto the temp circuit
                Stack.push(v);
                //remove the first edge, move to that node
                int tmp = *graph.list[v].begin();
                // if(tmp == endNode) {
                //     tmp = *(++graph.list[v].begin());
                // }
                graph.list[v].erase(tmp);
                graph.list[tmp].erase(v);
                v = tmp;
            }else{//if cur node has no edges
                Circuit.push_back(v);
                v = Stack.top();
                Stack.pop();
            }
        }
        if(endNode == -1){
            for(int i = 0; i < Circuit.size(); i++){
                cout << (Circuit[i]+1) << " ";
            }
        }
        int begin = 0;
        for(int i = 0; i < Circuit.size()-1; i++){
            if(Circuit[i] == startNode && Circuit[i+1] == endNode || 
               Circuit[i+1] == startNode && Circuit[i] == endNode){
                begin = i+1;
            }
        }
        int size = Circuit.size();
        for(int i = 0; i <  Circuit.size()-1; i++){
            cout << (Circuit[(begin + i) % size] + 1) << " ";
        }
       
    }
}
