class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        queue<int> q;
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!q.empty() && q.front() <= i-k) q.pop();
            if((nums[i] ^ (q.size()&1)) == 0) {
                q.push(i);
                ans++;
                if(i+k-1 >= n) return -1;
            }
        }
        return ans;
    }
};