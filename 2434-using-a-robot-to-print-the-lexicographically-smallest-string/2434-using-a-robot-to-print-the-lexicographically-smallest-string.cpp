class Solution {
public:
    string robotWithString(string s) {
        string ans;
        stack<char> st;
        int n = s.size();
        vector<int> lst(26, -1);
        for(int i = 0; i < n; i++) {
            lst[s[i]-'a'] = i;
        }
        for(int i = 0, j = 0; i < 26; i++) {
            while(!st.empty() && st.top()-'a' <= i) ans += st.top(), st.pop();
            if(j > lst[i]) continue;
            while(j <= lst[i]) {
                if(s[j]-'a' == i) ans += s[j];
                else st.push(s[j]);
                j++;
            }
        }
        while(!st.empty()) ans += st.top(), st.pop();
        return ans;
    }
};