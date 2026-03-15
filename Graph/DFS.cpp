#include <iostream>
#include <vector>
#include <list>
#include <queue>
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

    void DFShelper(int u, vector <bool> &vis){ //O(v + E)
        vis[u] = true;
        cout<<u<<" ";

        list<int> neighbours = l[u];
        for(int v : neighbours){
            if(!vis[v]){
                DFShelper(v, vis);
            }
        }  
    }

    void DFS(){
        vector <bool> vis(7, false);
        DFShelper(0, vis); //passing starting node and vector
        cout<<endl;
    }

};

int main() {
    Graph graph(7);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    graph.DFS();
    return 0;
}