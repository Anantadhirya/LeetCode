class Solution {
public:
    int lengthLongestPath(string input) {
        vector<string> split(1, "");
        stack<int> st;
        int ans = 0, tmp = 0, d = 0;
        bool file;
        for(auto c: input) {
            if(c == '\n') split.push_back("");
            else split.back() += c; 
        }
        for(auto s: split) {
            d = 0;
            file = 0;
            for(auto c: s) {
                if(c == '\t') d++;
                if(c == '.') file = 1;
            }
            while(st.size() > d) {
                tmp -= st.top();
                st.pop();
            }
            tmp += s.size() - d;
            st.push(s.size() - d);
            if(file) ans = max(ans, (int)(tmp + st.size() - 1));
        }
        return ans;
    }
};