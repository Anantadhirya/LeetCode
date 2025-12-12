class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](auto a, auto b) {
            if(a[1] != b[1]) return stoi(a[1]) < stoi(b[1]);
            else return (a[0] == "MESSAGE") < (b[0] == "MESSAGE");
        });
        set<int> online;
        queue<pair<int, int>> offline;
        int t;
        int idx;
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) online.insert(i);
        for(auto i: events) {
            t = stoi(i[1]);
            while(!offline.empty() && offline.front().first + 60 <= t) {
                online.insert(offline.front().second);
                offline.pop();
            }
            if(i[0] == "OFFLINE") {
                idx = stoi(i[2]);
                online.erase(idx);
                offline.push({t, idx});
            } else if(i[0] == "MESSAGE") {
                if(i[2] == "ALL") {
                    for(int i = 0; i < n; i++) ans[i]++;
                } else if(i[2] == "HERE") {
                    for(int i: online) ans[i]++;
                } else {
                    i[2].push_back(' ');
                    idx = 0;
                    for(char c: i[2]) {
                        if(c == ' ') {
                            ans[idx]++;
                            idx = 0;
                        } else if('0' <= c && c <= '9') idx = 10*idx + (c-'0');
                    }
                }
            }
        }
        return ans;
    }
};