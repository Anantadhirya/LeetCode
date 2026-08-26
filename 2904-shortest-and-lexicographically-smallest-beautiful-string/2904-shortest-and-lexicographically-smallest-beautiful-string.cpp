class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size(), len;
        pair<int, string> ans = {n+1, ""};
        deque<int> dq;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') dq.push_back(i);
            if(dq.size() > k) dq.pop_front();
            if(dq.size() == k) {
                len = i-dq.front()+1;
                if(len <= ans.first) ans = min(ans, {len, s.substr(dq.front(), len)});
            }
        }
        return ans.second;
    }
};