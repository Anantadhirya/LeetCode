class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>> pq;
        int n = apples.size();
        int ans = 0;
        for(int i = 0; i < n || !pq.empty(); i++) {
            if(i < n) pq.push({-(i+days[i]), apples[i]});
            while(!pq.empty() && (pq.top().second == 0 || -pq.top().first <= i)) pq.pop();
            if(!pq.empty()) {
                auto tmp = pq.top();
                pq.pop();
                tmp.second--;
                pq.push(tmp);
                ans++;
            }
        }
        return ans;
    }
};