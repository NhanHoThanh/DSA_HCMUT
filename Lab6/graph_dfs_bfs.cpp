#include <iostream>
#include <list>
using namespace std;

class Adjacency {
   private:
    list<int> adjList;
    int size;

   public:
    Adjacency() {}
    Adjacency(int V) {}
    void push(int data) {
        adjList.push_back(data);
        size++;
    }
    void print() {
        for (auto const &i : adjList)
            cout << " -> " << i;
    }
    void printArray() {
        for (auto const &i : adjList)
            cout << i << " ";
    }
    int getSize() { return adjList.size(); }
    int getElement(int idx) {
        auto it = adjList.begin();
        advance(it, idx);
        return *it;
    }
};

class Graph {
   private:
    int V;
    Adjacency *adj;

   public:
    Graph(int V) {
        this->V = V;
        adj = new Adjacency[V];
    }

    void addEdge(int v, int w) {
        adj[v].push(w);
        adj[w].push(v);
    }

    void printGraph() {
        for (int v = 0; v < V; ++v) {
            cout << "\nAdjacency list of vertex " << v << "\nhead ";
            adj[v].print();
        }
    }

    Adjacency *BFS(int v) {
        // v is a vertex we start BFS
        Adjacency *arr = new Adjacency(V);
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }
        list<int> queue;
        visited[v] = true;
        queue.push_back(v);

        while (!queue.empty()) {
            v = queue.front();
            arr->push(v);
            queue.pop_front();

            for (auto i = 0; i < adj[v].getSize(); ++i) {
                int neighbor = adj[v].getElement(i);
                if (!visited[neighbor]) {
                    queue.push_back(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return arr;
    }
    Adjacency *DFS(int v) {
        Adjacency *arr = new Adjacency(V);
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }
        list<int> stack;
        stack.push_back(v);
        while (!stack.empty()) {
            v = stack.back();
            stack.pop_back();
            if (!visited[v]) {
                visited[v] = true;
                arr->push(v);
            }
            for (int i = static_cast<int>(adj[v].getSize()) - 1; i >= 0; i--) {
                int neighbor = adj[v].getElement(i);
                if (!visited[neighbor]) {
                    stack.push_back(neighbor);
                }
            }
        }
        delete[] visited;
        return arr;
    }
};

/* If the DFS using stack dont work/ dont pass full testcases, you can try this recursion approach, which is simpler:
Adjacency *DFS(int v)
    {
        // v is a vertex we start DFS
                int numVer = this->adj->getSize();
                Adjacency* traversedList = new Adjacency;
                bool* visited = new bool[numVer];
                for (int i = 0; i < numVer; ++i) {
                        visited[i] = false;
                }
                this->DFSRec(v, visited, traversedList);
                delete[] visited;
                return traversedList;
        }

        void DFSRec(int v, bool* visited, Adjacency* &traversedList) {
                visited[v] = true;
                traversedList->push(v);

                int curSize = this->adj[v].getSize();
                for (int i = 0; i < curSize; ++i) {
                        int adjVer = this->adj[v].getElement(i);
                        if (!visited[adjVer])
                                this->DFSRec(adjVer, visited, traversedList);
                }
        }

*/

int main() {
    int V = 8, visited = 0;

    Graph g(V);
    Adjacency *arr;
    int edge[][2] = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {2, 5}, {2, 6}, {4, 6}, {6, 7}};
    for (int i = 0; i < 9; i++) {
        g.addEdge(edge[i][0], edge[i][1]);
    }

    // g.printGraph();
    // cout << endl;
    arr = g.DFS(visited);
    arr->printArray();
    delete arr;
}