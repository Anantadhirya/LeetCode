class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        map<char, int> lst;
        string vowels = "aiueo";
        for(const auto &c: vowels) {
            lst[c] = -1;
        }
        int idx, n = word.size();
        deque<int> cons;
        cons.push_back(-1);
        long long l, r;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            if(word[i] == 'a' || word[i] == 'i' || word[i] == 'u' || word[i] == 'e' || word[i] == 'o') {
                lst[word[i]] = i;
            } else {
                cons.push_back(i);
                if(cons.size() > k+1) cons.pop_front();
            }
            idx = n;
            for(const auto &c: vowels) {
                idx = min(idx, lst[c]);
            }
            if(idx != -1 && cons.size() == k+1) {
                l = 0, r = idx;
                l = max(l, (long long)cons[0]+1);
                r = min(r, (k == 0 ? i : (long long)cons[1]));
                if(l <= r) ans += (r-l+1);
            }
        }
        return ans;
    }
};