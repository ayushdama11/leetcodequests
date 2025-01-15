class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        unordered_map<int, int> m;
        for(int ele : arr) {
            m[ele]++;
        }
        for(int i=100; i<=999; i+=2) {  // even jumps
            int x = i;
            int a = x%10;   // ones place digit
            x /= 10;
            int b = x%10;   // tens place digit
            x /= 10;
            int c = x;  // hundreds place digit
            if(m.find(a)!=m.end()) {    // mtlb agar a hai set me
                m[a]--;
                if(m[a]<=0) m.erase(a);
                if(m.find(b)!=m.end()) {    // mtlb a and b dono hai set me 
                    m[b]--;
                    if(m[b]<=0) m.erase(b);
                    if(m.find(c)!=m.end()) {    // mtlb a b c teeno hai set me 
                        ans.push_back(i);
                    }
                    m[b]++;
                }
                m[a]++;
            }
        }
        return ans;
    }
};