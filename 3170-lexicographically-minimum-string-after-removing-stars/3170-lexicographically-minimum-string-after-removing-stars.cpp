class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<bool> d(n, false);
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; i++) {
            if(s[i] == '*') {
                d[i] = 1;
                if(!pq.empty()) {
                    d[pq.top().second] = 1;
                    pq.pop();
                }
            } else {
                pq.push({-(int)s[i], i});
            }
        }
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(!d[i]) ans += s[i];
        }
        return ans;
    }
};