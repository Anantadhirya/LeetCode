class KthLargest {
public:
    int n;
    priority_queue<int> pq;
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(const auto &i: nums) {
            pq.push(-i);
        }
    }
    
    int add(int val) {
        pq.push(-val);
        while(pq.size() > n) {
            pq.pop();
        }
        return -pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */