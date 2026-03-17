#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
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

    void print(){
        for(int u = 0; u<V; u++){ //0, 1, 2, 3, 4.
            list <int> neighbours = l[u];
            cout<<u<<" : ";
            for(int v : neighbours){
                cout<<v<<" ";
            }
            cout<<endl; 
        }
    }

    void pathHelper(int src, int dest, vector <bool> &vis, string &path){
        if(src == dest){
            cout<<path<<dest<<endl;
            return;
        }

        vis[src] = true;
        path += to_string(src);
        list <int> neighbours = l[src];

        for(int v : neighbours){
            if(!vis[v]){ //to prevent cycle
                pathHelper(v, dest, vis, path);
            }
        }

        path = path.substr(0, path.size()-1);
        vis[src] = false;
    }

    void printAllPaths(int src, int dest){
        vector <bool> vis(V, false);
        string path = "";
        pathHelper(src, dest, vis, path);
    }
};

int main() {
    Graph graph(6,false);

    graph.addEdge(0, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.printAllPaths(5, 1);
    return 0;
}