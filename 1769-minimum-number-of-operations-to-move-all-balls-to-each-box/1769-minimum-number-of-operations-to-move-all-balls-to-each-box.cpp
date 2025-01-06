class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), l = 0, r = 0;
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            if(boxes[i] == '1') ans[0] += i, r++;
        }
        for(int i = 1; i < n; i++) {
            if(boxes[i-1] == '1') l++, r--;
            ans[i] = ans[i-1] + l - r;
        }
        return ans;
    }
};