class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int l = 0, r = position.back() - position[0], mid;
        int ans = 0, tmp;
        while(l <= r) {
            mid = (l+r)/2;
            tmp = 1;
            for(int i = 1, j = 0; i < n; i++) {
                if(position[i] - position[j] >= mid) {
                    tmp++;
                    j = i;
                }
            }
            if(tmp >= m) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
};