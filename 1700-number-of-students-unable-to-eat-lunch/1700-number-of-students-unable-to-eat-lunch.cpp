class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> cnt(2, 0);
        for(const int &i: students) {
            cnt[i]++;
        }
        int n = sandwiches.size();
        for(int i = 0; i < n; i++) {
            if(cnt[sandwiches[i]] > 0) {
                cnt[sandwiches[i]]--;
            } else {
                return n - i;
            }
        }
        return 0;
    }
};