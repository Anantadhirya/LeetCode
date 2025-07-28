class Solution {
public:
    vector<int> v;
    Solution(vector<int>& nums) {
        v = nums;
    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
        vector<int> ret = v;
        std::random_shuffle(ret.begin(), ret.end());
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */