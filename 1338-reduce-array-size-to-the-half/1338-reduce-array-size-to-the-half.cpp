class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        map<int, int> cnt;
        for(auto &i: arr) cnt[i]++;
        vector<int> v;
        for(auto &[i, c]: cnt) v.push_back(c);
        sort(v.begin(), v.end());
        for(int i = v.size()-1, sm = 0; i >= 0; i--) {
            sm += v[i];
            if(sm >= (n+1)/2) return v.size()-i;
        }
        return -1;
    }
};