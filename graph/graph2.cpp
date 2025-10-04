#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
    }

    void dfs(int u, vector<int> &vis, stack<int> &s)
    {
        vis[u] = 1;

        for (auto v : l[u])
        {
            if (!vis[v])
            {
                dfs(v, vis, s);
            }
        }
        s.push(u);
    }

    void toposort()
    {
        vector<int> vis(V, 0);
        stack<int> s;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, s);
            }
        }

        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.toposort();
}