class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n, 0);
        for(int i = 0, x = 0; i < n; i++) {
            if(seq[i] == '(') {
                x++;
                if(x % 2 == 0) ans[i] = 1;
            } else if(seq[i] == ')') {
                if(x % 2 == 0) ans[i] = 1;
                x--;
            }
        }
        return ans;
    }
};