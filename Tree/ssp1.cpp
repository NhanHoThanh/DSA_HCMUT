#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int totalCost = 0;  // changed variable name from 'cost' to 'totalCost'
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        flow += f;
        totalCost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    if (flow < K)
        return -1;
    else
        return totalCost;
}

int main() {
    // Sample test case
    int N = 4;  // Number of nodes
    vector<Edge> edges = {
        {0, 1, 3, 2},  // Edge: from 0 to 1, capacity 3, cost 2
        {0, 2, 2, 5},  // Edge: from 0 to 2, capacity 2, cost 5
        {1, 2, 2, 1},  // Edge: from 1 to 2, capacity 2, cost 1
        {1, 3, 3, 4},  // Edge: from 1 to 3, capacity 3, cost 4
        {2, 3, 4, 3}   // Edge: from 2 to 3, capacity 4, cost 3
    };

    int K = 5;  // Desired flow
    int source = 0;
    int target = 3;

    int minCost = min_cost_flow(N, edges, K, source, target);
    if (minCost != -1) {
        cout << "Minimum cost to achieve flow " << K << " from node " << source
             << " to node " << target << " is: " << minCost << endl;
    } else {
        cout << "It is not possible to achieve flow " << K << " from node " << source
             << " to node " << target << endl;
    }

    return 0;
}
