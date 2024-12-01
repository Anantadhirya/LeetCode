class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = 0, j = 0; i < n; i++) {
            while(j < n && arr[j] < 2*arr[i]) j++;
            if(j < n && i != j && 2*arr[i] == arr[j]) return 1;
        }
        return 0;
    }
};