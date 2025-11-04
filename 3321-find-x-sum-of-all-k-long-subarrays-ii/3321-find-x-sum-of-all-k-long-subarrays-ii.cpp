class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long> ans;
        int n = nums.size();
        map<int, long long> freq;
        set<pair<long long, int>> s, s2;
        long long tmp = 0;
        for(int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }
        for(auto [i, c]: freq) {
            s.insert({c, i});
            tmp += c*i;
        }
        while(s.size() > x) {
            s2.insert(*s.begin());
            tmp -= s.begin()->first * s.begin()->second;
            s.erase(s.begin());
        }
        ans.push_back(tmp);
        for(int i = 0; i+k < n; i++) {
            if(s.erase({freq[nums[i+k]], nums[i+k]})) tmp -= freq[nums[i+k]] * nums[i+k];
            else s2.erase({freq[nums[i+k]], nums[i+k]});
            if(s.erase({freq[nums[i]], nums[i]})) tmp -= freq[nums[i]] * nums[i];
            else s2.erase({freq[nums[i]], nums[i]});

            freq[nums[i+k]]++;
            freq[nums[i]]--;

            while(s.size() < x && !s2.empty()) {
                auto it = s2.end();
                --it;
                tmp += it->first * it->second;
                s.insert(*it);
                s2.erase(it);
            }

            s.insert({freq[nums[i+k]], nums[i+k]});
            tmp += freq[nums[i+k]] * nums[i+k];
            if(nums[i] != nums[i+k]) {
                s.insert({freq[nums[i]], nums[i]});
                tmp += freq[nums[i]] * nums[i];
            }

            while(s.size() > x) {
                s2.insert(*s.begin());
                tmp -= s.begin()->first * s.begin()->second;
                s.erase(s.begin());
            }

            ans.push_back(tmp);
        }
        return ans;
    }
};