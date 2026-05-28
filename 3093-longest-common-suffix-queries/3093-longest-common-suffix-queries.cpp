class Solution {
public:
    void build(int sl, int sr, int si, vector<pair<int, int>> &st, vector<pair<string, int>> &arr) {
        if(sl == sr) {
            // length, index
            st[si] = {arr[sl].first.size(), arr[sl].second};
            return;
        }
        int sm = sl + sr >> 1;
        build(sl, sm, 2*si+1, st, arr);
        build(sm+1, sr, 2*si+2, st, arr);
        st[si] = min(st[2*si+1], st[2*si+2]);
    }
    pair<int, int> query(int l, int r, int sl, int sr, int si, vector<pair<int, int>> &st) {
        if(sr < l || r < sl) return {INT_MAX, INT_MAX};
        if(l <= sl && sr <= r) return st[si];
        int sm = sl + sr >> 1;
        return min(query(l, r, sl, sm, 2*si+1, st), query(l, r, sm+1, sr, 2*si+2, st));
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<pair<string, int>> arr;
        vector<int> ans;
        for(auto &s: wordsContainer) {
            reverse(s.begin(), s.end());
            arr.push_back({s, arr.size()});
        }
        sort(arr.begin(), arr.end());
        // for(auto i: arr) {
        //     cout << i.first << " " << i.second << "\n";
        // }
        vector<pair<int, int>> st(4*arr.size());
        build(0, arr.size()-1, 0, st, arr);
        
        for(auto &s: wordsQuery) {
            reverse(s.begin(), s.end());
            while(1) {
                int l, r;
                if(!s.empty()) {
                    l = lower_bound(arr.begin(), arr.end(), make_pair(s, -1)) - arr.begin();
                    s.back()++;
                    r = lower_bound(arr.begin(), arr.end(), make_pair(s, -1)) - arr.begin();
                    s.back()--;
                } else {
                    l = 0, r = arr.size();
                }
                // cout << s << " " << l << " " << r << "\n";
                if(l < r) {
                    ans.push_back(query(l, r-1, 0, arr.size()-1, 0, st).second);
                    break;
                }
                if(s.empty()) break;
                s.pop_back();
            }
        }
        return ans;
    }
};