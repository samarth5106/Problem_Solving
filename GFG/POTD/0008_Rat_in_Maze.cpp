class Solution {
  public:
  void solve(int x, int y, vector<vector<int>>& maze, int n,
               vector<vector<bool>>& visited, string path, vector<string>& paths){
                      // 1. Check boundaries and blocked/visited
        if (x < 0 || y < 0 || x >= n || y >= n || maze[x][y] == 0 || visited[x][y])
            return;

        // 2. Reached destination
        if (x == n - 1 && y == n - 1) {
            paths.push_back(path);
            return;
        }

        // 3. Mark current cell visited
        visited[x][y] = true;

        // 4. Explore all 4 directions
        solve(x + 1, y, maze, n, visited, path + 'D', paths); // Down
        solve(x, y - 1, maze, n, visited, path + 'L', paths); // Left
        solve(x, y + 1, maze, n, visited, path + 'R', paths); // Right
        solve(x - 1, y, maze, n, visited, path + 'U', paths); // Up

        // 5. Backtrack: unmark visited
        visited[x][y] = false;
               }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> paths;
    int n=maze[0].size();
        // If start or end blocked, no path
        if (maze[0][0] == 0 || maze[n-1][n-1] == 0)
            return paths;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        solve(0, 0, maze, n, visited, "", paths);

        return paths;
        
        
    }
};
