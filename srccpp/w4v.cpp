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

class Graph
{
  public:
    int n;
    vector<vector<int>> adjacencyList;
    vector<int> degree;

    Graph(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            vector<int> vec;
            adjacencyList.push_back(vec);
            degree.push_back(0);
        }
    }

    void addEdge(int u, int v)
    {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
        degree[v]++;
        degree[u]++;
    }
    vector<int> dfs(int begin, int end)
    {
        bool visited[n];

        stack<int> st;
    }
    void removeEdge(int from, int to)
    {
        remove(begin(adjacencyList[from]), end(adjacencyList[from]), to);
    }
};

int main()
{
    int numCases;
    cin >> numCases;

    for (int test = 0; test < numCases; test++)
    {
        int n, m;
        Graph graph(n);

        for (int i = 0; i < m; i++)
        {
            int from, to;
            cin >> from;
            cin >> to;
            graph.addEdge(from - 1, to - 1);
        }
        int startNode = -1;
        int endNode = -1;
        for (int i = 0; i < graph.inDegree.size(); i++)
        {
            if (graph.inDegree[i] % 2 == 1)
            {
                if (startNode != -1)
                {
                    startNode = i;
                }
                else if (endNode != -1)
                {
                    endNode = i;
                }
                else
                {
                    cout << "-1\n";
                    return;
                }
            }
        }
        if (startNode == -1)
        {
            startNode = 0;
            endNode = 0;
        }
        else if (endNode == -1)
        {
            endNode = 0;
            if (endNode == startNode)
            {
                endNode++;
            }
        }

        vector<int> trail = graph.dfs(startNode, endNode);
        for (int i = 0; i < trail.size() - 1; i++)
        {
            graph.removeEdge(trail[i], trail[i + 1]);
            graph.removeEdge(trail[i + 1], trail[i]);
        }
    }
}
