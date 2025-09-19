const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Spreadsheet {
public:
    vector<vector<int>> v;
    Spreadsheet(int rows) {
        v.assign(26, vector<int>(rows));
    }
    
    void setCell(string cell, int value) {
        int c = cell[0] - 'A';
        int r = stoi(cell.substr(1)) - 1;
        v[c][r] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
    }

    int get(string value) {
        if('A' <= value[0] && value[0] <= 'Z') {
            int c = value[0] - 'A';
            int r = stoi(value.substr(1)) - 1;
            return v[c][r];
        } else return stoi(value);
    }
    
    int getValue(string formula) {
        for(int i = formula.size()-1; i >= 1; i--) {
            if(formula[i] == '+') {
                return get(formula.substr(1, i-1)) + get(formula.substr(i+1));
            }
        }
        return -1;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */