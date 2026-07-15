
const int NN = 2e4 + 5;
const int MX = 1e4;
int st[4*NN];
void update(int i, int x, int sl = -MX, int sr = MX, int si = 0) {
	if(sl == sr) {
		st[si] += x;
		return;
	}
	int sm = (sl+sr+2*MX)/2-MX;
	if(i <= sm) update(i, x, sl, sm, 2*si+1);
	else update(i, x, sm+1, sr, 2*si+2);
	st[si] = st[2*si+1] + st[2*si+2];
}
int query(int l, int r, int sl = -MX, int sr = MX, int si = 0) {
	if(sr < l || r < sl) return 0;
	if(l <= sl && sr <= r) return st[si];
	int sm = (sl+sr+2*MX)/2-MX;
	return query(l, r, sl, sm, 2*si+1) + query(l, r, sm+1, sr, 2*si+2);
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        memset(st, 0, sizeof st);
        int n = nums.size();
        vector<int> ans(n);
        for(int i = n-1; i >= 0; i--) {
            ans[i] = query(-MX, nums[i]-1);
            update(nums[i], 1);
        }
        return ans;
    }
};