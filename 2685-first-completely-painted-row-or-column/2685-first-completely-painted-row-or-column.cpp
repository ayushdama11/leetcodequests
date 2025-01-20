class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();     // no. of rows
        int n = mat[0].size();      // no. of cols

        // s1 : creating lookup matrix
        vector<pair<int, int>> lookup(m*n+1);
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                lookup[mat[i][j]].first = i;
                lookup[mat[i][j]].second = j;
            }
        }

        // s2 : find earliest row / col painted
        vector<int> row_count(m,0);
        vector<int> col_count(n,0);

        for(int i=0; i<m*n; ++i) {
            pair<int, int> coordinate = lookup[arr[i]];
            int x = coordinate.first;
            int y = coordinate.second;
            row_count[x]++;
            col_count[y]++;
            if(row_count[x]==n || col_count[y]==m) {
                return i;
            }
        }

        return 0;
    }
};