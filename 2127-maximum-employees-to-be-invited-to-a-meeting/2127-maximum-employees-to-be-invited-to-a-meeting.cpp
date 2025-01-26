class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> in(n, 0), d(n, 1);
        for(const int &i: favorite) {
            in[i]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(in[i] == 0) q.push(i);
        }
        for(int curr; !q.empty(); ) {
            curr = q.front();
            q.pop();
            d[favorite[curr]] = max(d[favorite[curr]], d[curr] + 1);
            if(--in[favorite[curr]] == 0) q.push(favorite[curr]);
        }
        int one = 0, two = 0;
        for(int i = 0, len; i < n; i++) {
            if(in[i] == 0) continue;
            len = 0;
            for(int curr = i; in[curr]; curr = favorite[curr]) {
                in[curr] = 0;
                len++;
            }
            if(len == 2) two += d[i] + d[favorite[i]];
            else one = max(one, len);
        }
        return max(one, two);
    }
};