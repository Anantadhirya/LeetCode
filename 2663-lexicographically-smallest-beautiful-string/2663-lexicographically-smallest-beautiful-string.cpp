class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        int idx = -1;
        char c;
        for(int i = n-1; i >= 0; i--) {
            c = s[i]+1;
            if(i-1 >= 0 && c == s[i-1]) c++;
            if(i-2 >= 0 && c == s[i-2]) c++;
            if(i-1 >= 0 && c == s[i-1]) c++;
            if(c-'a'+1 > k) continue;
            idx = i;
            break;
        }
        if(idx == -1) return "";
        s[idx] = c;
        for(int i = idx+1; i < n; i++) {
            s[i] = 'a';
            if(i-1 >= 0 && s[i] == s[i-1]) s[i]++;
            if(i-2 >= 0 && s[i] == s[i-2]) s[i]++;
            if(i-1 >= 0 && s[i] == s[i-1]) s[i]++;
            if(s[i]-'a'+1 > k) return "";
        }
        return s;
    }
};