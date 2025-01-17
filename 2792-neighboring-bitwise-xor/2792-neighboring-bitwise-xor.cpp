class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // bool ans = false;
        int n = derived.size();
        vector<int> original(n);
        original[0] = 0;
        for(int i=0; i<n-1; i++) {
            original[i+1] = (derived[i] ^ original[i]);
        }
        // checking for zero as a first ele of orig
        bool checkZero = (original[0] ^ original[n-1]) == derived[n-1];

        original[0] = 1;
        for(int i=0; i<n-1; i++) {
            original[i+1] = (derived[i] ^ original[i]);
        }
        // checking for one as a first ele of orig
        bool checkOne = (original[n-1] ^ original[0]) == derived[n-1];
        return checkZero | checkOne;
    }
};