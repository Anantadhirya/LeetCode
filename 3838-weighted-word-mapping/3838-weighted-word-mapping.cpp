class Solution {
public:
    int w(string &s, vector<int> &weights) {
        int ret = 0;
        for(char &c: s) {
            ret += weights[c-'a'];
        }
        return ret;
    }
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(auto &s: words) {
            ans.push_back('z' - w(s, weights) % 26);
        }
        return ans;
    }
};