class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        map<int, int> cnt;
        int tmp;
        for(const auto &i: hand) {
            cnt[i]++;
        }
        while(!cnt.empty()) {
            tmp = cnt.begin()->first;
            for(int i = 0; i < groupSize; i++) {
                if(cnt[tmp+i] < 1) return 0;
                cnt[tmp+i]--;
            }
            while(!cnt.empty() && cnt.begin()->second <= 0) cnt.erase(cnt.begin());
        }
        return 1;
    }
};