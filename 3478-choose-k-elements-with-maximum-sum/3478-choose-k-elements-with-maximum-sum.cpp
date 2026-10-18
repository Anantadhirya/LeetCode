class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> v(n);
        vector<long long> ans(n);
        priority_queue<int> pq;
        long long sm = 0;
        for(int i = 0; i < n; i++) {
            v[i] = {nums1[i], i};
        }
        sort(v.begin(), v.end());
        for(int i = 0, j = 0; i < n; i++) {
            while(v[j].first < v[i].first) {
                sm += (long long)nums2[v[j].second];
                pq.push(-nums2[v[j].second]);
                j++;
            }
            while(pq.size() > k) {
                sm -= (long long)-pq.top();
                pq.pop();
            }
            ans[v[i].second] = sm;
        }
        return ans;
    }
};