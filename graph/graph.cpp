#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;

public: 
    Graph(int V){
        this->V=V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int i =0; i < V; i++){
            cout << i << " : " ;
            for(int it : l[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }

    void bfs(){
        queue<int> q;
        vector<int> vis(V, 0);

        q.push(0);
        vis[0] = 1;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            cout << u << " ";

            for(auto v : l[u]){
                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }

    void dfsHelper(int u, vector<int> &vis){
        cout<<u<<" ";
        vis[u] = 1;
        
        for(auto v : l[u]){
            if(!vis[v]){
                dfsHelper(v, vis);
            }
        }
    }
    void dfs(){
        int u = 0; 
        vector<int> vis(V,0);

        dfsHelper(u, vis);
    }

};


int main(){

    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.bfs();

    g.dfs();
}
