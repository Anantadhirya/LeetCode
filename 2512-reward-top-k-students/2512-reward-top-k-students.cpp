const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return NULL; }();

class Solution {
public:
    vector<string> split(string s) {
        vector<string> ret(1);
        for(const auto &c: s) {
            if(c == ' ') ret.push_back("");
            else ret.back() += c;
        }
        return ret;
    }
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        map<string, int> m;
        map<int, int> score;
        vector<int> ans(k);
        vector<pair<int, int>> score_pair;
        int n = report.size();
        for(const string &s: positive_feedback) {
            m[s] = 3;
        }
        for(const string &s: negative_feedback) {
            m[s] = -1;
        }
        for(int i = 0; i < n; i++) {
            for(const string &word: split(report[i])) {
                score[student_id[i]] += m[word];
            }
        }
        for(const auto &[id, x]: score) {
            score_pair.push_back({-x, id});
        }
        sort(score_pair.begin(), score_pair.end());
        for(int i = 0; i < k; i++) {
            ans[i] = score_pair[i].second;
        }
        return ans;
    }
};