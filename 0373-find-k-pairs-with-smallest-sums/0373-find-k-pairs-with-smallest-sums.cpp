class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums2.size();
        priority_queue<array<int, 3>> pq;
        vector<vector<int>> ans;
        int a, b;
        for(const int &i: nums1) {
            pq.push({-(i+nums2[0]), -i, 0});
        }
        while(k--) {
            a = -pq.top()[1];
            b = pq.top()[2];
            pq.pop();
            ans.push_back({a, nums2[b]});
            b++;
            if(b < n) pq.push({-(a+nums2[b]), -a, b});
        }
        return ans;
    }
};