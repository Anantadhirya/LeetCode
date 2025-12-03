class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<pair<pair<int, int>, int>, int> m;
        map<pair<int, int>, int> m2;

        map<array<int, 4>, int> mp;
        map<array<int, 3>, int> mp2;
        int n = points.size();
        int dx, dy, g, c, d;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                dx = points[i][0] - points[j][0];
                dy = points[i][1] - points[j][1];
                d = dx*dx + dy*dy;
                g = __gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;
                if(dx == 0) dy = abs(dy);
                if(dy == 0) dx = abs(dx);
                if(dx < 0) dx *= -1, dy *= -1;
                c = points[i][1] * dx - points[i][0] * dy;
                m[{{dx, dy}, c}]++;
                // cout << i << " " << j << " " << dx << " " << dy << " " << d << " " << c << " -> " << mp2[{dx, dy, d}] << " - " << mp[{dx, dy, d, c}] << "\n";
                ans -= mp2[{dx, dy, d}] - mp[{dx, dy, d, c}];
                mp[{dx, dy, d, c}]++;
                mp2[{dx, dy, d}]++;
            }
        }
        ans /= 2;
        for(auto [i, c]: m) {
            // cout << i.first.first << " " << i.first.second << " -> " << c << "\n";
            // cout << c << " * " << m2[i.first] << "\n";
            ans += c * m2[i.first];
            m2[i.first] += c;
        }
        return ans;
    }
};