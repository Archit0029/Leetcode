class Solution {
public:
    long long dfs(int r, int c,
                  vector<vector<int>>& grid,
                  vector<vector<bool>>& vis) {
        int m = grid.size();
        int n = grid[0].size();

        vis[r][c] = true;
        long long sum = grid[r][c];

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                grid[nr][nc] > 0 &&
                !vis[nr][nc]) {

                sum += dfs(nr, nc, grid, vis);
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] > 0 && !vis[i][j]) {
                    long long islandSum = dfs(i, j, grid, vis);

                    if (islandSum % k == 0)
                        ans++;
                }
            }
        }

        return ans;
    }
};