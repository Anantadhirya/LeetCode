class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> cnt;
        vector<int> v;
        int total = 0, ans = INT_MAX, tmp = 0;
        for(auto &i: word) {
            cnt[i]++;
        }
        for(auto &[_, i]: cnt) {
            v.push_back(i);
            total += i;
        }
        sort(v.begin(), v.end());
        tmp = total;
        for(int i = 0, j = 0; i < v.size(); i++) {
            while(j < v.size() && v[j] - v[i] <= k) {
                tmp -= v[j++];
            }
            ans = min(ans, int(tmp - (v[i] + k) * (v.size() - j)));
            tmp += v[i];
        }
        return ans;
    }
};