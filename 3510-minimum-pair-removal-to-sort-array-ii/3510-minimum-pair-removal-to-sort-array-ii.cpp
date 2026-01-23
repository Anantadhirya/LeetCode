class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        map<int, long long> m;
        set<pair<long long, int>> s;
        int n = nums.size(), cnt = 0, ans = 0, idx;
        for(int i = 0; i < n; i++) {
            m[i] = nums[i];
        }
        
        auto add = [&](pair<int, long long> a, pair<int, long long> b) -> void {
            s.insert({a.second+b.second, a.first});
            cnt += (a.second > b.second);
        };
        auto rem = [&](pair<int, long long> a, pair<int, long long> b) -> void {
            s.erase({a.second+b.second, a.first});
            cnt -= (a.second > b.second);
        };

        for(int i = 0; i+1 < n; i++) {
            add({i, nums[i]}, {i+1, nums[i+1]});
        }
        while(cnt) {
            idx = s.begin()->second;

            auto it = m.find(idx);
            auto itl = it, itr = it, itr2 = it;
            itl--, itr++, itr2++, itr2++;

            if(it != m.begin()) rem(*itl, *it);
            rem(*it, *itr);
            if(itr2 != m.end()) rem(*itr, *itr2);

            itr->second += it->second;

            if(it != m.begin()) add(*itl, *itr);
            if(itr2 != m.end()) add(*itr, *itr2);

            m.erase(it);
            ans++;
        }
        return ans;
    }
};