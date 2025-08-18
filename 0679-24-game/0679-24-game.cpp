class Solution {
public:
    vector<double> f(vector<double> &cards, int idx, int op) {
        vector<double> ret;
        for(int i = 0; i < cards.size(); i++) {
            if(i == idx) {
                switch(op) {
                    case 0:
                        ret.push_back(cards[i] + cards[i+1]);
                        break;
                    case 1:
                        ret.push_back(cards[i] - cards[i+1]);
                        break;
                    case 2:
                        ret.push_back(cards[i] * cards[i+1]);
                        break;
                    case 3:
                        ret.push_back(cards[i] / cards[i+1]);
                        break;
                }
                i++;
            } else ret.push_back(cards[i]);
        }
        return ret;
    }
    bool valid(vector<double> cards, map<vector<double>, bool> &memo) {
        if(memo.count(cards)) return memo[cards];
        bool &ret = memo[cards];
        if(cards.size() == 1) return ret = (abs(cards[0] - 24) <= 1e-7);
        for(int i = cards.size()-2; i >= 0; i--) {
            for(int j = 0; j < 4; j++) {
                if(valid(f(cards, i, j), memo)) return ret = 1;
            }
        }
        return ret = 0;
    }
    bool judgePoint24(vector<int>& cards) {
        map<vector<double>, bool> memo;
        for(int a = 0; a < 4; a++) {
            for(int b = 0; b < 4; b++) {
                if(b == a) continue;
                for(int c = 0; c < 4; c++) {
                    if(c == a || c == b) continue;
                    for(int d = 0; d < 4; d++) {
                        if(d == a || d == b || d == c) continue;
                        if(valid({(double)cards[a], (double)cards[b], (double)cards[c], (double)cards[d]}, memo)) return 1;
                    }
                }
            }
        }
        return 0;
    }
};