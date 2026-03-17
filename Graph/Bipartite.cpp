//Graph coloring approach

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

    bool isBipartite() { //Assuming entire graph is connected
        queue <int> q;
        vector <bool> vis(V, false);
        vector <int> color(V, -1);

        q.push(0);
        color[0] = 0;
        vis[0] = 0;

        while(q.size() > 0){
            int curr = q.front();
            q.pop();
            list <int> neighbours = l[curr];
            
            for(int v : neighbours){
                if(!vis[v]){
                    vis[v] = true;
                    color[v] = !color[curr]; //opposite color assigning
                    q.push(v);
                }
                else{
                    if(color[v] == color[curr]){ //same color of 2 adjacent vertices
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isBipartite2() { //Without vis array check
        queue <int> q;
        vector <int> color(V, -1);

        q.push(0);
        color[0] = 0;

        while(q.size() > 0){
            int curr = q.front();
            q.pop();
            list <int> neighbours = l[curr];
            
            for(int v : neighbours){
                if(color[v] == -1){
                    color[v] = !color[curr]; //opposite color assigning
                    q.push(v);
                }
                else{
                    if(color[v] == color[curr]){ //same color of 2 adjacent vertices
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    //undirected
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(3, 4);

    cout<<graph.isBipartite2()<<endl;
    return 0;
}