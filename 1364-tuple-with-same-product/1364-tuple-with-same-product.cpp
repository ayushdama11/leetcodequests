class Solution {
public:
    int nC2(int n) {
        return (n*(n-1)/2);     // n pairs mese 2 ka group nikalna hai islie 
    }
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                mp[nums[i]*nums[j]]++;
            }
        }
        int count = 0;
        for(auto e : mp) {
            count += 8 * nC2(e.second);
        }

        return count;
    }
};