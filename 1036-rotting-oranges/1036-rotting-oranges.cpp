class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        // bfs
        queue<pair <pair<int, int>, int> > q;
        int cntfresh = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {     // rotten
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else if (grid[i][j] == 1) {
                    cntfresh++;
                }
                else {      // '0'
                    vis[i][j] = 0;
                }
            }
        }

        int time = 0;
        int cnt = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            for(int i=0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                while(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol] != 2 and grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 2;
                    cnt++;
                    q.push({{nrow, ncol}, t+1});
                } 
            }
        } 

        if(cnt != cntfresh) return -1;

        return time;

    }
};