class Solution {

private :
    void dfs(vector<vector<int>> &image, vector<vector<int>> &ans, int row, int col, int color, int iniCol, int delrow[], int delcol[]) {
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();

        for(int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and image[nrow][ncol]==iniCol and ans[nrow][ncol]!=color) {
                dfs(image, ans, nrow, ncol, color, iniCol, delrow, delcol);
            }
        }
    }

public :
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniCol = image[sr][sc];
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>> ans = image;
        dfs(image, ans, sr, sc, color, iniCol, delrow, delcol);

        return ans;
    }
};