class FindSumPairs {
public:
    vector<int> n2;
    unordered_map<int, int> m1, m2;
    int ans;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        for(const int &i: nums1) {
            m1[i]++;
        }
        n2 = nums2;
        for(const int &i: nums2) {
            m2[i]++;
        }
    }
    
    void add(int index, int val) {
        m2[n2[index]]--;
        n2[index] += val;
        m2[n2[index]]++;
    }
    
    int count(int tot) {
        ans = 0;
        for(const auto &[i, c]: m1) {
            if(m2.count(tot-i)) ans += c * m2[tot-i];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */