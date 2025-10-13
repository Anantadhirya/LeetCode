class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans, sorted;
        for(string &i: words) {
            ans.push_back(i);
            sort(i.begin(), i.end());
            if(!sorted.empty() && sorted.back() == i) ans.pop_back();
            else sorted.push_back(i);
        }
        return ans;
    }
};