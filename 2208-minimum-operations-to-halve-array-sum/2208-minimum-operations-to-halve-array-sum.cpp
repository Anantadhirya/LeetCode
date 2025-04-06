class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sm = 0, curr;
        for(const int &i: nums) {
            pq.push(i);
            sm += i;
        }
        sm /= 2;
        int ans = 0;
        while(sm > 0) {
            curr = pq.top();
            pq.pop();
            sm -= curr/2;
            curr /= 2;
            ans++;
            pq.push(curr);
        }
        return ans;
    }
};