#include <bits/stdc++.h>
using namespace std;
int find(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void unionSets(vector<int>& parent, int x, int y) {
    int xRoot = find(parent, x);
    int yRoot = find(parent, y);
    parent[xRoot] = yRoot;
}

int numberOfFriendGroups(vector<vector<int>>& graph) {
    vector<vector<int>> edges;
    for (int i = 0; i < static_cast<int>(graph.size()); i++) {
        for (int j : graph[i]) {
            if (i != j)
                edges.push_back({i, j});
        }
    }
    int n = graph.size();
    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (const auto& edge : edges) {
        unionSets(parent, edge[0], edge[1]);
    }

    unordered_set<int> uniqueParents;
    for (int i = 0; i < n; i++) {
        uniqueParents.insert(find(parent, i));
    }

    return uniqueParents.size();
}
