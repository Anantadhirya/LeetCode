class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        bitset<9> bi[n], bj[n], bb[3][3];
        for(int i = 0, p; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '.') continue;
                p = board[i][j] - '1';
                if(bi[i][p]) return false;
                if(bj[j][p]) return false;
                if(bb[i/3][j/3][p]) return false;
                bi[i][p] = 1;
                bj[j][p] = 1;
                bb[i/3][j/3][p] = 1;
            }
        }
        return true;
    }
};