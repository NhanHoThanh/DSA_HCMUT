#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>
using namespace std;

struct Graph {
    int V, E;
    vector<pair<int, pair<int, int>>> edges;
    // Constructor
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({w, {u, v}});
    }

    // YOUR CODE HERE
    int find(vector<int>& parent, int i) {
        if (i != parent[i])
            parent[i] = find(parent, parent[i]);
        return parent[i];
    }
    int kruskalMST() {
        sort(edges.begin(), edges.end());

        vector<int> parent(V);
        for (int i = 0; i < V; ++i)
            parent[i] = i;

        int mst_weight = 0;
        for (auto& edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            int set_u = find(parent, u);
            int set_v = find(parent, v);

            if (set_u != set_v) {
                mst_weight += edge.first;
                parent[set_u] = set_v;
            }
        }

        return mst_weight;
    }
};