const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        sort(queries.begin(), queries.end());
        int curr = 0;
        vector<int> f(n+1, 0);
        priority_queue<int> pq;
        int ans = 0;
        for(int i = 0, j = 0; i < n; i++) {
            curr -= f[i];
            while(j < m && queries[j][0] <= i)
                pq.push(queries[j++][1]);
            while(curr < nums[i] && !pq.empty() && i <= pq.top()) {
                curr++;
                f[pq.top()+1]++;
                pq.pop();
            }
            if(curr < nums[i]) return -1;
        }
        return pq.size();
    }
};