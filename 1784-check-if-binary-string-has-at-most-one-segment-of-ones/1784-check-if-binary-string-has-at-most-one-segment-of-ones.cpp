class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                for(int j = i+1; j < n; j++) {
                    if(s[j] == '0') {
                        for(int k = j+1; k < n; k++) {
                            if(s[k] != '0') return 0;
                        }
                    }
                }
                return 1;
            }
        }
        return 1;
    }
};