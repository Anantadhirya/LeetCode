class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sm = 0;
        int n = capacity.size();
        sort(capacity.begin(), capacity.end());
        for(int i: apple) sm += i;
        for(int i = n-1; i >= 0; i--) {
            sm -= capacity[i];
            if(sm <= 0) return n-i;
        }
        return -1;
    }
};