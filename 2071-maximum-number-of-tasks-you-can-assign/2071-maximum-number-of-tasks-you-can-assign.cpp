class Solution {
public:
    int n, m;
    deque<int> dq;
    bool check(vector<int> &tasks, vector<int> &workers, int pills, int &strength, int &k) {
        dq.clear();
        for(int i = k-1, j = m-1; i >= 0; i--) {
            while(j >= m-k && tasks[i] <= workers[j] + strength) dq.push_front(workers[j--]);
            if(dq.empty()) return 0;
            if(tasks[i] <= dq.back()) dq.pop_back();
            else {
                if(pills > 0) dq.pop_front(), pills--;
                else return 0;
            }
        }
        return 1;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        n = tasks.size();
        m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int l = 0, r = min(n, m), mid, ans = -1;
        while(l <= r) {
            mid = (l+r)/2;
            if(check(tasks, workers, pills, strength, mid)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
};