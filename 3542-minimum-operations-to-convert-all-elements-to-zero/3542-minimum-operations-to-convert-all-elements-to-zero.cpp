class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> s;
        int ans = 0;
        for(auto i: nums) {
            if(i > 0 && !s.count(i)) {
                ans++;
                s.insert(i);
            }
            while(!s.empty()) {
                auto it = s.end();
                --it;
                if(*it > i) s.erase(it);
                else break;
            }
        }
        return ans;
    }
};