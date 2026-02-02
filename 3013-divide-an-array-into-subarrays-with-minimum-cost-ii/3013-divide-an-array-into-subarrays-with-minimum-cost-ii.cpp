class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long ans = LLONG_MAX, sm = 0;
        set<pair<int, int>> s, s2;
        for(int i = n-1; i >= 1; i--) {
            if(i+dist+1 < n) {
                if(s.count({nums[i+dist+1], i+dist+1})) {
                    sm -= nums[i+dist+1];
                    s.erase({nums[i+dist+1], i+dist+1});
                    if(!s2.empty()) {
                        auto tmp = *s2.begin();
                        sm += tmp.first;
                        s.insert(tmp);
                        s2.erase(s2.begin());
                    }
                } else {
                    s2.erase({nums[i+dist+1], i+dist+1});
                }
            }
            if(s.size() == k-2) {
                ans = min(ans, nums[0] + nums[i] + sm);
            }
            sm += nums[i];
            s.insert({nums[i], i});
            if(s.size() > k-2) {
                auto it = s.end();
                --it;
                s2.insert(*it);
                sm -= it->first;
                s.erase(it);
            }
        }
        return ans;
    }
};