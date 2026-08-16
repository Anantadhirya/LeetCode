class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3, 0), tmp;
        int sm, move, pick;
        for(int &i: stones) cnt[i%3]++;

        // cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << "\n";
        if(cnt[1] == 0 && cnt[2] == 0) return 0;

        for(int first = 1; first <= 2; first++) {
            if(cnt[first] == 0) continue;
            tmp = cnt;
            // cout << "start " << first << "\n";

            move = 1;
            tmp[first]--;
            sm = first;
            while(tmp[0] + tmp[1] + tmp[2] > 0) {
                if(tmp[sm] > 0) pick = sm;
                else if(tmp[0] > 0) pick = 0;
                else pick = 3-sm;
                // cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << " -> " << sm << "\n";
                move++;
                tmp[pick]--;
                sm = (sm+pick)%3;
                if(sm == 0) {
                    if(move % 2 == 0) return 1;
                    break;
                }
            }

        }

        return 0;
    }
};