class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> s;
        vector<int> tmp, lst;
        for(const int &i: arr) {
            swap(lst, tmp);
            lst.push_back(0);
            tmp.clear();
            for(const int &j: lst) {
                if(!tmp.empty() && (j|i) == tmp.back()) continue;
                tmp.push_back(j|i);
                s.insert(j|i);
            }
        }
        return s.size();
    }
};