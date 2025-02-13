class Solution {

private : 
    void dfs(int node, vector<vector<int> > &adjL, vector<int> & vis) {
        vis[node] = 1;
        for(int i : adjL[node]) {
            if(!vis[i]) {
                dfs(i, adjL, vis);
            }
        }
    }

public :
    int findCircleNum(vector<vector<int>>& adjM) {
        int n = adjM.size(); // rows
        int m = adjM[0].size();     // cols
        vector<vector<int> > adjL(n);    // adjacency list

        // convert adjacency matrix into adjacency list
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(adjM[i][j]==1 && i!=j) {
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int count = 0;

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                count++;
                dfs(i, adjL, vis);
            }
        }

        return count;
    }
};