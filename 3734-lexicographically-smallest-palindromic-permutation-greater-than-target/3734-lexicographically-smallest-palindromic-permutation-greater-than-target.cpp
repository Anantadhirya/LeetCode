class Solution {
public:
    string checkEqual(int &n, int &odd_ch, vector<int> cnt, string &target) {
        string eq;
        for(int i = 0, c; i < n/2; i++) {
            c = target[i]-'a';
            if(cnt[c] < 2) return "";
            eq.push_back('a'+c);
            cnt[c] -= 2;
        }
        if(odd_ch != -1) eq.push_back('a'+odd_ch);
        for(int i = n/2-1; i >= 0; i--) {
            eq.push_back(eq[i]);
        }
        if(eq > target) return eq;
        return "";
    }
    string lexPalindromicPermutation(string s, string target) {
        vector<int> cnt(26, 0), tmp(26, 0);
        int n = target.size(), odd_ch = -1;
        int idx = -1, ch = -1;
        string ans, eq;
        for(char &c: s) cnt[c-'a']++;
        for(int i = 0; i < 26; i++) {
            if(cnt[i]&1) {
                if(odd_ch != -1) return "";
                odd_ch = i;
            }
        }

        tmp = cnt;
        for(int i = 0, c; i < n/2; i++) {
            c = target[i]-'a';
            for(int j = c+1; j < 26; j++) {
                if(tmp[j] >= 2) {
                    idx = i;
                    ch = j;
                    break;
                }
            }
            if(tmp[c] < 2) break;
            tmp[c] -= 2;
        }

        eq = checkEqual(n, odd_ch, cnt, target);
        if(eq != "") return eq;
        if(idx == -1) return "";
        for(int i = 0; i < idx; i++) {
            ans.push_back(target[i]);
            cnt[target[i]-'a'] -= 2;
        }
        ans.push_back('a'+ch);
        cnt[ch] -= 2;
        for(int j = 0; j < 26; j++) {
            while(cnt[j] >= 2) ans.push_back('a'+j), cnt[j] -= 2;
        }
        if(odd_ch != -1) ans.push_back('a'+odd_ch);
        for(int i = n/2-1; i >= 0; i--) {
            ans.push_back(ans[i]);
        }
        return ans;
    }
};