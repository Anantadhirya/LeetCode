class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string tmp = "";
        int n = target.size();
        for(int i = 0; i < n; i++) {
            tmp.push_back('a');
            ans.push_back(tmp);
            while(tmp[i] < target[i]) {
                tmp[i]++;
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};