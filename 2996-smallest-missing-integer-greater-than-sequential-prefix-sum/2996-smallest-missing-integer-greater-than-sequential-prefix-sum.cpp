class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sm = nums[0];
        bool stop = 0;
        bitset<51> ada;
        ada[nums[0]] = 1;
        for(int i = 1; i < n; i++) {
            ada[nums[i]] = 1;
            if(!stop && nums[i] == nums[i-1] + 1) sm += nums[i];
            else stop = 1;
        }
        while(sm <= 50 && ada[sm]) sm++;
        return sm;
    }
};