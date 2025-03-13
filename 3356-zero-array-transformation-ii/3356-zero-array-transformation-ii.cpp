const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return nullptr; }();

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size(), ans = 0;
        int l, r, val;
        vector<int> arr(n+1);
        for(int i = 0; i < n; i++) {
            while(arr[i] < nums[i]) {
                if(ans == m) return -1;
                l = queries[ans][0];
                r = queries[ans][1];
                val = queries[ans++][2];
                
                if(r < i) continue;
                arr[max(l, i)] += val;
                arr[r+1] -= val;
            }
            arr[i+1] += arr[i];
        }
        return ans;
    }
};