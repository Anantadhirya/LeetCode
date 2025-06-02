class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> mni, mxi, mnj, mxj;
        mni = mnj = vector<int>(n+1, INT_MAX);
        mxi = mxj = vector<int>(n+1, INT_MIN);
        int ans = 0;
        for(const auto &i: buildings) {
            mni[i[0]] = min(mni[i[0]], i[1]);
            mxi[i[0]] = max(mxi[i[0]], i[1]);
            mnj[i[1]] = min(mnj[i[1]], i[0]);
            mxj[i[1]] = max(mxj[i[1]], i[0]);
        }
        for(const auto &i: buildings) {
            ans += (mni[i[0]] < i[1] && i[1] < mxi[i[0]] && mnj[i[1]] < i[0] && i[0] < mxj[i[1]]);
        }
        return ans;
    }
};