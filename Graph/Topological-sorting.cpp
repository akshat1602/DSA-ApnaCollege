#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <stack>
using namespace std;

class Graph{
    int V;
    list <int> *l;
    bool isUndirected;

public:
    Graph(int V, bool isUndirected = true){
        this->V = V;
        l = new list <int> [V]; //dynamic array to store neighbours
        this->isUndirected = isUndirected;
    }

    void addEdge(int u, int v){ //u--->v
        l[u].push_back(v);
        if(isUndirected){
            l[v].push_back(u);
        }
    }

    void topoHelper(int src, vector <bool> &vis, stack<int> &s){ //DFS
        vis[src] = true;

        list <int> neighbours = l[src];
        for(int v : neighbours){
            if(!vis[v]){
                topoHelper(v, vis, s);
            }
        }

        s.push(src);
    }

    void topoSort(){
        vector <bool> vis(V, false);
        stack<int> s;

        for(int i = 0; i<V; i++){
            if(!vis[i]){
                topoHelper(i, vis, s);
            }
        }

        //Print topological Order
        while(s.size() > 0){
            cout<<s.top()<< " ";
            s.pop();
        }
        cout<<endl;
    }
};

int main() {
    //DAG
    Graph graph(6, false);

    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.topoSort();
    
    return 0;
}