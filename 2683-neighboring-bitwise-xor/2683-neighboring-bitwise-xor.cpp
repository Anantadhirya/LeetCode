class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        bool ans = 1;
        for(const int &i: derived) {
            ans ^= i;
        }
        return ans;
    }
};