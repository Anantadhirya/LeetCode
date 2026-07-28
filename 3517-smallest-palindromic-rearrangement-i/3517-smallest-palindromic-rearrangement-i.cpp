class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        sort(s.begin(), s.begin()+n/2);
        for(int i = 0, j = n-1; i <= j; i++, j--) {
            s[j] = s[i];
        }
        return s;
    }
};