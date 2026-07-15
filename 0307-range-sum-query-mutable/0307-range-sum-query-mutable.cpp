const int NN = 3e4 + 5;
class NumArray {
public:
    int st[4*NN];
    int N;
    void st_build(vector<int> &nums, int si, int sl, int sr) {
        if(sl == sr) {
            st[si] = nums[sl];
            return;
        }
        int sm = (sl+sr)/2;
        st_build(nums, 2*si+1, sl, sm);
        st_build(nums, 2*si+2, sm+1, sr);
        st[si] = st[2*si+1] + st[2*si+2];
    }
    void st_update(int i, int x, int si, int sl, int sr) {
        if(sl == sr) {
            st[si] = x;
            return;
        }
        int sm = (sl+sr)/2;
        if(i <= sm) st_update(i, x, 2*si+1, sl, sm);
        else st_update(i, x, 2*si+2, sm+1, sr);
        st[si] = st[2*si+1] + st[2*si+2];
    }
    int st_query(int l, int r, int si, int sl, int sr) {
        if(sr < l || r < sl) return 0;
        if(l <= sl && sr <= r) return st[si];
        int sm = (sl+sr)/2;
        return st_query(l, r, 2*si+1, sl, sm) + st_query(l, r, 2*si+2, sm+1, sr);
    }
    NumArray(vector<int>& nums) {
        N = nums.size();
        st_build(nums, 0, 0, N-1);
    }
    
    void update(int index, int val) {
        st_update(index, val, 0, 0, N-1);
    }
    
    int sumRange(int left, int right) {
        return st_query(left, right, 0, 0, N-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */