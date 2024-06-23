class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), ans = 0;
        multiset<int> s;
        for(int i = 0, j = 0; i < n; i++) {
            s.insert(nums[i]);
            while(*(--s.end()) - *(s.begin()) > limit) {
                s.erase(s.find(nums[j++]));
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};