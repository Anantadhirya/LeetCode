const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    bool solve(string &curr, int &n, int &k) {
        if(curr.size() == n) return (--k == 0);
        for(char c = 'a'; c <= 'c'; c++) {
            if(!curr.empty() && c == curr.back()) continue;
            curr.push_back(c);
            if(solve(curr, n, k)) return 1;
            curr.pop_back();
        }
        return 0;
    }
    string getHappyString(int n, int k) {
        string curr = "";
        solve(curr, n, k);
        return curr;
    }
};