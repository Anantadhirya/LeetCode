class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<bool> valid(n, 1);
        vector<int> t(n);
        vector<string> name(n), city(n);
        vector<string> ans, split(4);
        int idx;
        for(int i = 0; i < n; i++) {
            idx = 0;
            split.assign(4, "");
            for(char &c: transactions[i]) {
                if(c == ',') idx++;
                else split[idx] += c;
            }
            t[i] = stoi(split[1]);
            name[i] = split[0];
            city[i] = split[3];
            for(int j = 0; j < i; j++) {
                if(name[i] == name[j] && city[i] != city[j] && abs(t[j] - t[i]) <= 60) valid[i] = valid[j] = 0;
            }
            if(stoi(split[2]) > 1000) valid[i] = 0;
        }
        for(int i = 0; i < n; i++) {
            if(!valid[i]) ans.push_back(transactions[i]);
        }
        return ans;
    }
};