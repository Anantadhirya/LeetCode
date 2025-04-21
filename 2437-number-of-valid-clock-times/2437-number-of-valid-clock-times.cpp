class Solution {
public:
    int countTime(string time) {
        int ans = 1;
        if(time[0] == '?' && time[1] == '?') ans = 24;
        else if(time[1] == '?') ans = (time[0] == '2' ? 4 : 10);
        else if(time[0] == '?') ans = 2 + (time[1] <= '3');

        if(time[3] == '?') ans *= 6;
        if(time[4] == '?') ans *= 10;
        
        return ans;
    }
};