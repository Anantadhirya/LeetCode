class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = seats.size();
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }
};