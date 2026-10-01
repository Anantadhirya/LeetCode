class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<array<int, 3>> v(5, {0, -1, -1});
        for(int i = 0, idx; i < n; i++) {
            if(s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o') {
                if(s[i] == 'a') idx = 0;
                else if(s[i] == 'i') idx = 1;
                else if(s[i] == 'u') idx = 2;
                else if(s[i] == 'e') idx = 3;
                else if(s[i] == 'o') idx = 4;
                v[idx][0]--;
                if(v[idx][1] == -1) v[idx][1] = i, v[idx][2] = s[i];
            }
        }
        sort(v.begin(), v.end());
        for(int i = 0, j = 0; i < n; i++) {
            if(s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o') {
                while(v[j][0] == 0) j++;
                s[i] = v[j][2];
                v[j][0]++;
            }
        }
        return s;
    }
};