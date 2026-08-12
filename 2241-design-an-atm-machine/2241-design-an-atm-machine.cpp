class ATM {
public:
    vector<int> b;
    vector<int> v = {20, 50, 100, 200, 500};
    ATM() {
        b.assign(5, 0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < 5; i++) {
            b[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5, 0);
        for(int i = 4; i >= 0; i--) {
            ans[i] = min(b[i], amount/v[i]);
            amount -= ans[i] * v[i];
        }
        if(amount != 0) return {-1};
        for(int i = 0; i < 5; i++) {
            b[i] -= ans[i];
        }
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */