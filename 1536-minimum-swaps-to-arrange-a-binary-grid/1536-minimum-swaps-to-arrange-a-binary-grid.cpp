class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> v(n, -1);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0) v[i] = j;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(v[j] <= i) {
                    for(int k = j; k-1 >= i; k--) {
                        swap(v[k-1], v[k]);
                        ans++;
                    }
                    break;
                }
            }
            if(v[i] > i) return -1; 
        }
        return ans;
    }
};