class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ret = 0;
        sort(cost.begin(), cost.end(), greater<int>());
        for(int i = 0; i < cost.size(); i++) {
            if(i % 3 != 2) ret += cost[i];
        }
        return ret;
    }
};