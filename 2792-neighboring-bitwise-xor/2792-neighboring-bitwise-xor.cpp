class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorsum = 0;
        for(int i : derived) xorsum ^= i;
        return xorsum == 0;
    }
};