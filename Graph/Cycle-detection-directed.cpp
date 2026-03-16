//Directed 

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
    
    bool DirCycleHelper(int src, vector<bool> &vis, vector<bool> &recPath){
        vis[src] = true;
        recPath[src] = true;
        list <int> neighbours = l[src];

        for(int v : neighbours){
            if(!vis[v]){
                if(DirCycleHelper(v, vis, recPath)){ //means cycle exist
                    return true;
                }
            }
            else{
                if(recPath[v]){ //recursion path mein aajae
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false; //no cycle exists
    }

    bool isCycleDir() {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(DirCycleHelper(i, vis, recPath)){
                    return true;
                }
            }
        }
        return false;
    }

};

int main() {
    //Directed
    Graph graph(4, false);
    graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);

    cout<<graph.isCycleDir()<<endl;

    return 0;
}