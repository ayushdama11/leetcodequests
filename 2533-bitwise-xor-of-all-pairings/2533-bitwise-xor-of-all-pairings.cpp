class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int m = nums2.size();
        if(m&1) {  // agr m ki size odd hai tb xor in ans
            for(int i : nums1) ans ^= i;
        }
        int n = nums1.size();
        if(n&1) {
            for(auto i : nums2) ans ^= i;
        }
        return ans;
    }
};