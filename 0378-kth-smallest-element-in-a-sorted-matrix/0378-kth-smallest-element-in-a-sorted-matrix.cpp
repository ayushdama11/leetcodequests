class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        for(int i=0; i<n; i++) {
            pq.push({matrix[i][0], i, 0});
        }
        int result = 0;
        for(int i=0; i<k; i++) {
            auto topele = pq.top();
            pq.pop();
            result = topele[0];

            int row = topele[1], col = topele[2];
            if(col+1<n) {
                pq.push({matrix[row][col+1], row, col+1});
            }
        }

        return result;
    }
};