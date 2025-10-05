#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<int>>& visited) {
        visited[i][j] = 1;
        for (auto &d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
            // flow from lower to higher (reverse)
            if (!visited[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                dfs(heights, ni, nj, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        // Pacific: top row and left column
        for (int i = 0; i < m; i++) dfs(heights, i, 0, pacific);
        for (int j = 0; j < n; j++) dfs(heights, 0, j, pacific);

        // Atlantic: bottom row and right column
        for (int i = 0; i < m; i++) dfs(heights, i, n-1, atlantic);
        for (int j = 0; j < n; j++) dfs(heights, m-1, j, atlantic);

        // Find common cells
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
