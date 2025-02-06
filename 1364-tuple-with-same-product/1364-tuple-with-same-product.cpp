class Solution {
public:
    int fact(int n) {
        return (n*(n-1)/2);     // n pairs mese 2 ka group nikalna hai islie 
    }
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                mp[nums[i]*nums[j]]++;
            }
        }
        for(auto e : mp) {
            count += 8 * fact(e.second);
        }

        return count;
    }
};