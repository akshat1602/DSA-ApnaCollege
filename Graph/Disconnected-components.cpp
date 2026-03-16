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
    
    //BFS
    void BFShelper(int st, vector <bool> &vis){ //O(V + E) 

        queue <int> q;
        q.push(st); //source vertex
        vis[st] = true;

        while(q.size() > 0){
            int u = q.front();
            q.pop();
            cout<<u<<" ";

            list <int> neightbours = l[u];//u-----v
            for(int v : neightbours){
                if(!vis[v]){
                    vis[v] = true; //means now that node is visited.
                    q.push(v);
                }
            }
        }

        cout<<endl;
    }

    void BFS(){
        vector <bool> vis(7, false);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                BFShelper(i, vis); //starting pt = i.
                cout<<endl;
            }
        }
    }
    
    //DFS
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
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                DFShelper(i, vis); //starting pt = i.
                cout<<endl;
            }
        }
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