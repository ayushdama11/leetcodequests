class Solution {
public:
    int minimumLength(string s) {
        int ans = 0;
        unordered_map<char, int> m;
        for(auto e : s) {
            m[e]++;
        }
        for(auto e : m) {
            if(e.second % 2 == 0) ans+=2;
            else ans+=1;
        }
        return ans;
    }
};