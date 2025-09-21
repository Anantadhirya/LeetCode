class MovieRentingSystem {
public:
    map<pair<int, int>, bool> av;
    map<pair<int, int>, int> pr;
    map<int, priority_queue<pair<int, int>>> unrented;
    priority_queue<pair<int, pair<int, int>>> rented;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(const auto &i: entries) {
            av[{i[0], i[1]}] = 1;
            pr[{i[0], i[1]}] = i[2];
            unrented[i[1]].push({-i[2], -i[0]});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ret;
        priority_queue<pair<int, int>> &pq = unrented[movie];
        while(ret.size() < 5 && !pq.empty()) {
            if(av[{-pq.top().second, movie}]) {
                av[{-pq.top().second, movie}] = 0;
                ret.push_back(-pq.top().second);
            }
            pq.pop();
        }
        for(const int &shop: ret) {
            pq.push({-pr[{shop, movie}], -shop});
            av[{shop, movie}] = 1;
        }
        return ret;
    }
    
    void rent(int shop, int movie) {
        av[{shop, movie}] = 0;
        rented.push({-pr[{shop, movie}], {-shop, -movie}});
    }
    
    void drop(int shop, int movie) {
        av[{shop, movie}] = 1;
        unrented[movie].push({-pr[{shop, movie}], -shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ret;
        pair<int, int> tmp;
        while(ret.size() < 5 && !rented.empty()) {
            tmp = {-rented.top().second.first, -rented.top().second.second};
            if(!av[tmp]) av[tmp] = 1, ret.push_back({tmp.first, tmp.second});
            rented.pop();
        }
        for(const auto &i: ret) {
            rented.push({-pr[{i[0], i[1]}], {-i[0], -i[1]}});
            av[{i[0], i[1]}] = 0;
        }
        return ret;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */