//Undirected

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
using namespace std;

class Graph{
    int V;
    list <int> *l;
public:
    Graph(int V){
        this->V = V;
        l = new list <int> [V]; //dynamic array to store neighbours
    }

    void addEdge(int u, int v){ //u---v
        l[u].push_back(v);
        l[v].push_back(u);
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
    
    bool undirCycleHelper(int src, int parent, vector<bool> &vis){
        vis[src] = true;
        list <int> neighbours = l[src];

        for(int v : neighbours){
            if(!vis[v]){
                if(undirCycleHelper(v, src, vis)){ //means cycle exist
                    return true;
                }
            }
            else{
                if(v != parent){ //non-parent logic se cycle detected
                    return true;
                }
            }
        }
        return false; //no cycle exists
    }

    bool isCycleUndir() {
        vector<bool> vis(V, false);
        return undirCycleHelper(0, -1, vis);
    }

};

int main() {
    int V = 5;
    Graph graph(V);
    
    //undirected
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(3, 4);

    cout<<graph.isCycleUndir()<<endl;
    return 0;
}