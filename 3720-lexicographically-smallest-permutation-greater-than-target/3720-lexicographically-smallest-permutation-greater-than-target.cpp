class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = target.size(), idx = -1, ch = -1;
        string ans;
        vector<int> cnt(26, 0), tmp;
        for(char &c: s) cnt[c-'a']++;
        tmp = cnt;
        for(int i = 0, c; i < n; i++) {
            c = target[i]-'a';
            for(int j = c+1; j < 26; j++) {
                if(tmp[j] > 0) {
                    idx = i;
                    ch = j;
                    break;
                }
            }
            if(tmp[c] == 0) break;
            tmp[c]--;
        }

        if(idx == -1) return "";
        
        for(int i = 0; i < idx; i++) {
            ans.push_back(target[i]);
            cnt[target[i]-'a']--;
        }
        ans.push_back('a'+ch);
        cnt[ch]--;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < cnt[i]; j++) ans.push_back('a'+i);
        }
        return ans;
    }
};