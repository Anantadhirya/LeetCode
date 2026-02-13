class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans1 = 0, ans2 = 0, ans3 = 0;
        map<int, int> fi;
        map<pair<int, int>, int> fi2;
        for(int i = 0, j = 0; i < n; i++) {
            if(s[j] != s[i]) j = i;
            ans1 = max(ans1, i-j+1);
        }
        for(char skip = 'a', c; skip <= 'c'; skip++) {
            fi.clear();
            fi[0] = -1;
            c = (skip == 'a' ? 'b' : skip == 'b' ? 'c' : 'a');
            for(int i = 0, pref = 0; i < n; i++) {
                if(s[i] == skip) {
                    pref = 0;
                    fi.clear();
                    fi[0] = i;
                } else {
                    pref += (s[i] == c ? 1 : -1);
                    if(fi.count(pref)) ans2 = max(ans2, i - fi[pref]);
                    else fi[pref] = i;
                }
            }
        }
        fi2[{0, 0}] = -1;
        for(int i = 0, d1 = 0, d2 = 0; i < n; i++) {
            if(s[i] == 'a') d1++, d2++;
            else if(s[i] == 'b') d1--;
            else if(s[i] == 'c') d2--;
            if(fi2.count({d1, d2})) ans3 = max(ans3, i - fi2[{d1, d2}]);
            else fi2[{d1, d2}] = i;
        }
        return max(ans1, max(ans2, ans3));
    }
};