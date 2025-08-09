class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sm = 0, mx = 0;
        for(const int &i: milestones) {
            sm += (long long)i;
            mx = max(mx, (long long)i);
        }
        sm -= mx;
        return sm + min(mx, sm+1);
    }
};