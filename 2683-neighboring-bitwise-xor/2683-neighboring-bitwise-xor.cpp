class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans = 0;
        for(const int &i: derived) {
            ans ^= i;
        }
        return ans == 0;
    }
};