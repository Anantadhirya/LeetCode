class Solution {
public:
    string pushDominoes(string dominoes) {
        stack<int> s;
        int n = dominoes.size();
        s.push(n);
        for(int i = n-1; i >= 0; i--) {
            if(dominoes[i] != '.') s.push(i);
        }
        for(int i = 0, lst = -1, nxt, l, r; i < n; i++) {
            while(s.top() < i) s.pop();
            nxt = s.top();
            if(dominoes[i] != '.') {
                lst = i;
                continue;
            }

            l = (lst != -1 && dominoes[lst] == 'R' ? i - lst : n);
            r = (nxt != n && dominoes[nxt] == 'L' ? nxt - i : n);
            dominoes[i] = (l == r ? '.' : l < r ? 'R' : 'L');
        }
        return dominoes;
    }
};