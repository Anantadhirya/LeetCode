class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1); hFences.push_back(m);
        vFences.push_back(1); vFences.push_back(n);
        int h = hFences.size(), v = vFences.size();
        int ans = -1;
        const int MOD = 1e9 + 7;
        set<int> s;
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        for(int i = 0; i < h; i++) {
            for(int j = i+1; j < h; j++) {
                s.insert(hFences[j] - hFences[i]);
            }
        }
        for(int i = 0; i < v; i++) {
            for(int j = i+1; j < v; j++) {
                if(s.count(vFences[j] - vFences[i])) {
                    ans = max(ans, vFences[j] - vFences[i]);
                }
            }
        }
        return ans == -1 ? -1 : (long long)ans*ans % MOD;
    }
};