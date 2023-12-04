#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> onTheSand(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;

    // Step 2
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // Step 3
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty()) {
        pair<int, int> cell = q.front();
        q.pop();
        for (pair<int, int>& dir : dirs) {
            int new_i = cell.first + dir.first, new_j = cell.second + dir.second;
            if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && dist[new_i][new_j] > dist[cell.first][cell.second] + 1) {
                dist[new_i][new_j] = dist[cell.first][cell.second] + 1;
                q.push({new_i, new_j});
            }
        }
    }

    // Step 4
    return dist;
}
