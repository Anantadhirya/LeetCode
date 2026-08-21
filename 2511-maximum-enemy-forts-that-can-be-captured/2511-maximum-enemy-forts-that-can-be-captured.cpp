class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        int ans = 0;
        for(int i = 0, lst = -1; i < n; i++) {
            if(forts[i] == 0) continue;
            
            if(lst != -1 && forts[i] != forts[lst]) ans = max(ans, i-lst-1);
            lst = i;
        }
        return ans;
    }
};