class Solution {
public:
    int n, m;
    vector<int> dq;
    int front, back;
    bool check(vector<int> &tasks, vector<int> &workers, int pills, int &strength, int &k) {
        front = back = 0;
        for(int i = k-1, j = m-1; i >= 0; i--) {
            while(j >= m-k && tasks[i] <= workers[j] + strength) dq[back++] = (workers[j--]);
            if(front == back) return 0;
            if(tasks[i] <= dq[front]) front++;
            else {
                if(pills > 0) back--, pills--;
                else return 0;
            }
        }
        return 1;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        n = tasks.size();
        m = workers.size();
        dq.resize(m);
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