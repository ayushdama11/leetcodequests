class Solution {
public:
    int dfs(vector<vector<int>>& arr, int i, int j) {
        if(i<0 || j<0 || i>=arr.size() || j>=arr[0].size() || arr[i][j]==0) return 0;
        int total = arr[i][j];
        arr[i][j] = 0;
        total += dfs(arr, i, j+1);
        total += dfs(arr, i, j-1);
        total += dfs(arr, i+1, j);
        total += dfs(arr, i-1, j);
        return total;
    }
    int findMaxFish(vector<vector<int>>& arr) {
        int mx = 0;
        int m = arr.size() , n = arr[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][j]>0) {
                    mx = max(mx, dfs(arr, i, j));
                }
            }
        }
        return mx;
    }
};