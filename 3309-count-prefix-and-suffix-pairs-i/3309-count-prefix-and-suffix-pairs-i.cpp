class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2) {
        int len1 = str1.size();
        int len2 = str2.size();

        if(len1 > len2) return false;
        if(str2.substr(0, len1) != str1) return false;  // prefix check
        if(str2.substr(len2-len1) != str1) return false;    // suffix check
        else return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        int n = words.size();
        int count = 0;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }
};