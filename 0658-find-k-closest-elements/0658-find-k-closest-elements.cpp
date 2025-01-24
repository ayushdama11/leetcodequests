class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pi> pq;      // {distance, element}
        for(auto ele : arr) {
            int dist = abs(x-ele);
            pi p = {dist, ele};
            pq.push(p);
            if(pq.size()>k) pq.pop();
        } 
        vector<int> ans;
        while(pq.size()>0) {
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};