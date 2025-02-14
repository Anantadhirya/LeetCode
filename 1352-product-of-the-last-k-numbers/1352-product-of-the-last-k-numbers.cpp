class ProductOfNumbers {
public:
    int idx = 0;
    vector<pair<int, int>> v;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        idx++;
        if(num == 1) return;
        if(num == 0) v.clear();
        v.push_back({idx, num});
    }
    
    int getProduct(int k) {
        int ans = 1;
        for(int i = v.size()-1; i >= 0 && idx - v[i].first < k; i--) {
            ans *= v[i].second;
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */