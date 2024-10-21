class Solution {
public:
    int maxUniqueSplit(string s) {
        int n = s.size();
        int ans = 0;

        bool valid;
        string tmp;
        unordered_set<string> st;
        
        for(int mask = (1<<(n-1)); mask < (1<<n); mask++) {
            valid = 1;
            tmp = "";
            st.clear();
            for(int i = 0; i < n; i++) {
                tmp += s[i];
                if((mask>>i)&1) {
                    if(st.count(tmp)) {
                        valid = 0;
                        break;
                    } else {
                        st.insert(tmp);
                        tmp = "";
                    }
                }
            }
            if(valid) ans = max(ans, __builtin_popcount(mask));
        }
        return ans;
    }
};