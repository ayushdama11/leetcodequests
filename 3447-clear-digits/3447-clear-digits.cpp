class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for(char i : s) {
            if(isdigit(i)) ans.pop_back();
            else ans.push_back(i);
        }
        return ans;
    }
};