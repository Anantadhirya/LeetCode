class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        bitset<100> b;
        vector<int> ans;
        for(auto i: nums) {
            if(b[i]) ans.push_back(i);
            b[i] = 1;
        }
        return ans;
    }
};