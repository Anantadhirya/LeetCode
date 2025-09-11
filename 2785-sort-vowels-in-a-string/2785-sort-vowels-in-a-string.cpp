class Solution {
public:
    string sortVowels(string s) {
        string vstr = "AIUEOaiueo";
        int idx = 0;
        vector<char> vowels;
        for(const auto &i: s) {
            if(vstr.find(i) != string::npos) {
                vowels.push_back(i);
            }
        }
        ranges::sort(vowels);
        for(auto &i: s) {
            if(vstr.find(i) != string::npos) {
                i = vowels[idx++];
            }
        }
        return s;
    }
};