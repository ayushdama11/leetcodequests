class Solution {
public:
    typedef pair<int,int> pii;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        int n = tasks.size();
        // create 3 column vector - containing ids as third column
        for(int i=0; i<n; i++) {
            tasks[i].push_back(i);
        }
        // sort the task on basis of enq
        sort(tasks.begin(), tasks.end());

        long long timer = tasks[0][0];
        int i = 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;      // {processing_time, index}

        while(!pq.empty() || i<n) {

            // put all the tasks into min heap whose enqueu time is less than or equal to timer
            while(i<n && timer>=tasks[i][0]) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            // if min heap is empty
            if(pq.empty()) {
                timer = tasks[i][0];
            }
            // not empty
            else {
                ans.push_back(pq.top().second);
                timer += pq.top().first;
                pq.pop();
            }
        }

        return ans;
    }
};