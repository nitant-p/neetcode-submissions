class Solution {
public:

    int islands = 0;

    void dfs(int r, int c, 
        vector<vector<bool>>& marked,
        vector<vector<char>>& grid) {
        if (r < 0 || r >= marked.size() || c < 0 || c >= marked[0].size()) {
            return;
        } else{
            if (grid[r][c] == '1' && !marked[r][c]) {
                marked[r][c] = true;
                dfs(r + 1, c, marked, grid);
                dfs(r, c + 1, marked, grid);
                dfs(r - 1, c, marked, grid);
                dfs(r, c - 1, marked, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));


        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, visited, grid);
                    ++islands;
                }
            }
        }

        return islands;
    }
};