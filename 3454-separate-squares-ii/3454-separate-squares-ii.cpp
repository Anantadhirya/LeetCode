struct Node {
    Node *l, *r;
    int upd, cnt;
};

void update(int l, int r, int val, Node *cur, int sl, int sr, vector<int> &xs) {
    if(xs[sr+1] <= l || r <= xs[sl]) return;
    if(l <= xs[sl] && xs[sr+1] <= r) {
        cur->upd += val;
    } else {
        int sm = (sl+sr)/2;
        if(!cur->l) cur->l = new Node();
        if(!cur->r) cur->r = new Node();
        update(l, r, val, cur->l, sl, sm, xs);
        update(l, r, val, cur->r, sm+1, sr, xs);
    }
    cur->cnt = 0;
    if(cur->upd > 0) cur->cnt = (xs[sr+1]-xs[sl]);
    else {
        if(cur->l) cur->cnt += cur->l->cnt;
        if(cur->r) cur->cnt += cur->r->cnt;
    }
}

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        Node* root = new Node();
        vector<array<int, 4>> v;
        vector<pair<double, int>> areas;
        set<int> s;
        vector<int> xs;
        int prev_y = 0, idx, n;
        double area, dA, dy;
        for(const auto &i: squares) {
            s.insert(i[0]);
            s.insert(i[0]+i[2]);
            v.push_back({i[1], i[0], i[0]+i[2], 1});
            v.push_back({i[1]+i[2], i[0], i[0]+i[2], -1});
        }
        xs.assign(s.begin(), s.end());
        n = xs.size();
        xs.push_back(xs.back()+1);
        sort(v.begin(), v.end());
        for(const auto &[y, l, r, val]: v) {
            area += (double)(y - prev_y) * root->cnt;
            areas.push_back({area, y});
            update(l, r, val, root, 0, n-1, xs);
            prev_y = y;
        }
        idx = lower_bound(areas.begin(), areas.end(), make_pair(area/2, -1)) - areas.begin() - 1;
        dA = areas[idx+1].first - areas[idx].first;
        dy = areas[idx+1].second - areas[idx].second;
        return areas[idx].second + dy * (area/2 - areas[idx].first) / dA;
    }
};