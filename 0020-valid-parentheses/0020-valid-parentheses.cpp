class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        string tmp;
        for(const auto &i: s) {
            if(i == ')' || i == '}' || i == ']') {
                if(st.empty()) return 0;
                tmp = "";
                tmp += st.top();
                tmp += i;
                if(tmp != "()" && tmp != "{}" && tmp != "[]") return 0;
                st.pop();
            } else st.push(i);
        }
        return st.empty();
    }
};