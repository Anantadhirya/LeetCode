class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        bool sorted = 0;
        pair<int, int> mn;
        while(1) {
            sorted = 1;
            mn = {INT_MAX, -1};
            for(int i = 0; i+1 < nums.size(); i++) {
                if(nums[i] > nums[i+1]) sorted = 0;
                mn = min(mn, {nums[i] + nums[i+1], i});
            }
            if(sorted) break;
            ans++;
            nums.erase(nums.begin()+mn.second, nums.begin()+mn.second+2);
            nums.insert(nums.begin()+mn.second, mn.first);
        }
        return ans;
    }
};