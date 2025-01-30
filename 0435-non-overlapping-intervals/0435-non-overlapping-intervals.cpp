bool comp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);

        int end = INT_MIN;
        int ans = 0;    // total elements to remove
        for(int i=0; i<n; i++) {
            if(end<=intervals[i][0]) {  // than it is not overlaping
                end = intervals[i][1];
            } else {
                ans++;
            }
        }

        return ans;
    }
};