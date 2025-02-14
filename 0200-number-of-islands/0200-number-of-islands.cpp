class Solution {

private :
    void bfs (int row, int col, vector<vector<int> > &vis, vector<vector<char>> &grid) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // now we will basically traverse the neighbours and if 1 than we will mark them visited
            for(int delrow = -1; delrow <= 1; delrow++) {
                for(int delcol = -1; delcol <= 1; delcol++) {
                    int nrow = row + delrow;    // neighbour row
                    int ncol = col + delcol;    // neighbour col
                    // Up
                    if(row-1 >= 0 && grid[row-1][col] == '1' && !vis[row-1][col]) {
                        vis[row-1][col] = 1;
                        q.push({row-1, col});
                    }
                    // Right
                    if(col+1 < m && grid[row][col+1] == '1' && !vis[row][col+1]) {
                        vis[row][col+1] = 1;
                        q.push({row, col+1});
                    }
                    // Down
                    if(row+1 < n && grid[row+1][col] == '1' && !vis[row+1][col]) {
                        vis[row+1][col] = 1;
                        q.push({row+1, col});
                    }
                    // Left
                    if(col-1 >= 0 && grid[row][col-1] == '1' && !vis[row][col-1]) {
                        vis[row][col-1] = 1;
                        q.push({row, col-1});
                    }
                }
            }
        }
    }

public :
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // 2d vector visited 
        vector<vector<int> > vis(n, vector<int>(m, 0));
        int count = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    bfs(i, j, vis, grid);
                }
            }
        }

        return count;
    }
};