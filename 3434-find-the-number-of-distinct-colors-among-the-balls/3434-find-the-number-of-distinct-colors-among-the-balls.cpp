class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int, int> tballs;     // total balls 
        unordered_map<int, int> tcolours;   // total colrs
        int distinct = 0;
        for(auto e : queries) {
            int ball = e[0];
            int colour = e[1];
            if(tballs.find(ball)!=tballs.end()) {       // agr ball k pas phle se colour hai 
                int old = tballs[ball];
                tcolours[old]--;
                if(tcolours[old]==0) distinct--;
            }
            tballs[ball] = colour;
            tcolours[colour]++;

            if(tcolours[colour]==1) distinct++;
            ans.push_back(distinct);
        }
        return ans;
    }
};