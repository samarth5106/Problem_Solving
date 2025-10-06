class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
          int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // Min-heap: {maxElevationSoFar, x, y}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        while (!pq.empty()) {
            auto [elev, x, y] = pq.top();
            pq.pop();

            if (visited[x][y]) continue;
            visited[x][y] = true;

            if (x == n - 1 && y == n - 1) return elev;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    int nextElev = max(elev, grid[nx][ny]);
                    pq.push({nextElev, nx, ny});
                }
            }
        }

        return -1;
        
    }
};
