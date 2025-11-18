class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(), idx = 0;
        while(idx < n-1) {
            if(bits[idx]) idx += 2;
            else idx++;
        }
        return idx == n-1;
    }
};