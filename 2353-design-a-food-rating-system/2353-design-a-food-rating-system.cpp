class FoodRatings {
public:
    map<string, pair<string, int>> m;
    map<string, set<pair<int, string>>> s;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++) {
            m[foods[i]] = {cuisines[i], ratings[i]};
            s[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        pair<string, int> p = m[food];
        s[p.first].erase({-p.second, food});
        
        p.second = newRating;

        m[food] = p;
        s[p.first].insert({-p.second, food});
    }
    
    string highestRated(string cuisine) {
        return s[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */