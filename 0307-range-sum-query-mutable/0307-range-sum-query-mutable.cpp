const int NN = 3e4 + 5;
int N;
int st[4*NN];

void st_update(int i, int x, int sl = 0, int sr = N-1, int si = 0) {
	if(sl == sr) {
		st[si] = x;
		return;
	}
	int sm = (sl+sr)/2;
	if(i <= sm) st_update(i, x, sl, sm, 2*si+1);
	else st_update(i, x, sm+1, sr, 2*si+2);
	st[si] = st[2*si+1] + st[2*si+2];
}
int st_query(int l, int r, int sl = 0, int sr = N-1, int si = 0) {
	if(sr < l || r < sl) return 0;
	if(l <= sl && sr <= r) return st[si];
	int sm = (sl+sr)/2;
	return st_query(l, r, sl, sm, 2*si+1) + st_query(l, r, sm+1, sr, 2*si+2);
}

class NumArray {
public:
    NumArray(vector<int>& nums) {
        N = nums.size();
        for(int i = 0; i < N; i++) {
            update(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        st_update(index, val);
    }
    
    int sumRange(int left, int right) {
        return st_query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */