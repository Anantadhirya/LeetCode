class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int mn = 0, mx = 0;
        bool sorted = 1;
        for(int i = 0; i < n; i++) {
            if(s[i] < s[mn]) mn = i; // min terkiri
            if(s[i] >= s[mx]) mx = i; // max terkanan 
            if(i-1 >= 0 && s[i-1] > s[i]) sorted = 0;
        }
        if(sorted) return 0;
        if(n == 2 && !sorted) return -1;
        if(mn == 0 || mx == n-1) return 1;
        if(mn == n-1 && mx == 0) return 3;
        else return 2;
    }
};