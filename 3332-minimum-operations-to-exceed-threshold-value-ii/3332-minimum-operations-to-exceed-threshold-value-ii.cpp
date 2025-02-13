class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        priority_queue<long long, vector<long long>, greater<long long> > pq(nums.begin(), nums.end());
        // for(auto n : nums) pq.push(n);
        while(pq.size()>1 && pq.top()<k) {
            long long n1 = pq.top();
            pq.pop();
            long long n2 = pq.top();
            pq.pop();
            pq.push(n1*2 + n2);
            ans++;
        }
        return ans;
    }
};