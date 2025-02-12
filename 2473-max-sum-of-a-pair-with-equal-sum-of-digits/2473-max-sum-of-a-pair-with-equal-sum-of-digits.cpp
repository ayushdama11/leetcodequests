class Solution {
public:

    int f(int n) {
        int sum = 0;
        while(n>0) {
            sum += (n%10);
            n /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = -1;
        for(auto n : nums) {
            int sum = f(n);
            if(mp.find(sum) != mp.end()) ans = max(ans, mp[sum] + n);
            mp[sum] = max(mp[sum], n);
        }
        return ans;
    }
};