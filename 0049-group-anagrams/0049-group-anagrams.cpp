class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(string str : arr) {
            string lexo = str;
            sort(lexo.begin(), lexo.end());
            if(mp.find(lexo)==mp.end()) {    // not in map then create mapping
                vector<string> v;
                v.push_back(str);
                mp[lexo] = v;
            } else {    // lexo already there in map
                mp[lexo].push_back(str);
            }
        }

        // push_back all the strings to ans
        for(auto x : mp) {
            vector<string> v = x.second;
            ans.push_back(v);
        }

        return ans;
    }
};