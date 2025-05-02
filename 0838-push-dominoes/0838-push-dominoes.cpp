class Solution {
public:
    string pushDominoes(string dominoes) {
        stack<int> s;
        int n = dominoes.size();
        for(int i = 0, lst = -1, nxt = 0, l, r; i < n; i++) {
            if(dominoes[i] != '.') {
                lst = i;
                continue;
            }
            while(nxt < i || (nxt < n && dominoes[nxt] == '.')) nxt++;

            l = (lst != -1 && dominoes[lst] == 'R' ? i - lst : n);
            r = (nxt != n && dominoes[nxt] == 'L' ? nxt - i : n);
            dominoes[i] = (l == r ? '.' : l < r ? 'R' : 'L');
        }
        return dominoes;
    }
};