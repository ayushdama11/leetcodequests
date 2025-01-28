class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i : nums) {
            pq.push(i);
        }
        int sum = 0;
        while(k>0) {
            int x = pq.top();
            pq.pop();
            x = x*-1;
            pq.push(x);
            k--;
        }
        while(pq.size()>0) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};