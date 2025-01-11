class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.length()) return false;
        unordered_map<char, int> m;
        for(char c : s) {
            m[c]++;
        }
        // count characters with odd freq
        int oddC = 0;
        for(auto oc : m) {
            if(oc.second % 2 != 0) oddC++;
        }

        return k>=oddC;
    }
};