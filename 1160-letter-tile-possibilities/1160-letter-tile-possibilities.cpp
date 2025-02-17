class Solution {

private :
    int ways(vector<int>& freq) {
        int w = 0;  // ways
        for(int i=0; i<26; i++) {
            if(freq[i] > 0) {
                freq[i]--;
                w += 1 + ways(freq);
                freq[i]++;
            }
        }
        return w;
    }

public :
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for(char c : tiles) {
            freq[c-'A']++;
        }
        return ways(freq);
    }
};