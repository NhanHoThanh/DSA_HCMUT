#include <iostream>
#include <list>
#include <vector>
using namespace std;

class DirectedGraph {
    int V;
    list<int>* adj;

   public:
    DirectedGraph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }
    bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack) {
        visited[v] = true;
        recStack[v] = true;

        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i] && isCyclicUtil(*i, visited, recStack)) {
                return true;
            } else if (recStack[*i]) {
                return true;
            }
        }
        recStack[v] = false;  // remove the vertex from recursion stack
        return false;
    }

    bool isCyclic() {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyclicUtil(i, visited, recStack)) {
                    return true;
                }
            }
        }
        return false;
    }
};
