class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0);
        for(string b : words2) {
            vector<int> freq(26,0);
            for(char c : b) {
                freq[c-'a']++;
            }
            for(int i=0; i<26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        vector<string> res;

        for(string a : words1) {
            vector<int> freq(26,0);
            for(char c : a) {
                freq[c-'a']++;
            }
            bool isUniversal = true;
            for(int i=0; i<26; i++) {
                if(freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }

            if(isUniversal) res.push_back(a);
        }
        return res;
    }
};