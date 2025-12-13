class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<int, string>> v;
        vector<string> ans;
        int n = code.size();
        int x;
        for(int i = 0; i < n; i++) {
            if(businessLine[i] == "electronics") x = 0;
            else if(businessLine[i] == "grocery") x = 1;
            else if(businessLine[i] == "pharmacy") x = 2;
            else if(businessLine[i] == "restaurant") x = 3;
            else x = -1;
            if(code[i].empty()) x = -1;
            for(char &j: code[i]) {
                if('a' <= j && j <= 'z' || 'A' <= j && j <= 'Z' || '0' <= j && j <= '9' || j == '_') continue;
                x = -1;
                break;
            }
            if(!isActive[i]) x = -1;
            if(x != -1) v.push_back({x, code[i]});
        }
        sort(v.begin(), v.end());
        for(auto [_, i]: v) ans.push_back(i);
        return ans;
    }
};