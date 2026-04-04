class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int col = n/rows, idx;
        string ans;
        for(int j = 0; j < col; j++) {
            for(int i = 0; i < rows; i++) {
                idx = col*i + (i+j);
                if(idx < n) ans.push_back(encodedText[idx]);
                else break;
            }
        }
        while(!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};