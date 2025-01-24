class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;     // {ele, freq}
        for(int i=0; i<n; i++) mp[arr[i]]++;
        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        for(auto x : mp) {
            int ele = x.first, freq = x.second;
            pair<int, int> p = {freq, ele};
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(pq.size()>0) {
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }
};