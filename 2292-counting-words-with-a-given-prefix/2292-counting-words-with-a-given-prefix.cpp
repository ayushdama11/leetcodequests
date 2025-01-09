class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int n1 = words.size();
        int n2 = pref.size();
        for(int i=0; i<n1; i++) {
            if(words[i].substr(0,n2) == pref) count++;
        }
        return count;
    }
};