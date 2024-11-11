class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<bool> prime(mx+1, 1);
        vector<int> primes;
        for(int i = 2; i <= mx; i++) {
            if(!prime[i]) continue;
            primes.push_back(i);
            for(int j = i*i; j <= mx; j += i) {
                prime[j] = 0;
            }
        }
        for(int i = n-2, p; i >= 0; i--) {
            // A[i] - p < A[i+1]
            // A[i] - A[i+1] < p
            if(nums[i] < nums[i+1]) continue;
            p = upper_bound(primes.begin(), primes.end(), nums[i] - nums[i+1]) - primes.begin();
            if(p == primes.size() || primes[p] >= nums[i]) {
                return 0;
            }
            nums[i] -= primes[p];
        }
        return 1;
    }
};