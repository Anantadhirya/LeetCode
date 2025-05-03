const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int top = 0, bottom = 0, same = 0;
        for(int i = 0; i < n; i++) {
            same += (tops[i] == bottoms[i]);
            if(tops[0] == tops[i] || tops[0] == bottoms[i])
                top += (tops[0] != tops[i]);
            else top = n+1;
            if(bottoms[0] == bottoms[i] || bottoms[0] == tops[i])
                bottom += (bottoms[0] != bottoms[i]);
            else bottom = n+1;
        }
        if(top <= n) top = min(top, n-top-same);
        if(bottom <= n) bottom = min(bottom, n-bottom-same);
        if(top > n && bottom > n) return -1;
        else return min(top, bottom);
    }
};