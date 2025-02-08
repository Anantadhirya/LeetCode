class NumberContainers {
public:
    map<int, int> arr;
    map<int, priority_queue<int>> pos;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        arr[index] = number;
        pos[number].push(-index);
    }
    
    int find(int number) {
        while(!pos[number].empty() && arr[-pos[number].top()] != number) pos[number].pop();
        return pos[number].empty() ? -1 : -pos[number].top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */