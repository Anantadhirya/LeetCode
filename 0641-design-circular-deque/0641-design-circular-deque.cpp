class MyCircularDeque {
public:
    int n, cnt, l, r;
    vector<int> v;
    MyCircularDeque(int k) {
        n = k;
        v.resize(n);
        cnt = 0;
        l = 1, r = 0;
    }
    
    bool insertFront(int value) {
        if(cnt == n) return 0;
        cnt++;
        l = (l-1+n)%n;
        v[l] = value;
        return 1;
    }
    
    bool insertLast(int value) {
        if(cnt == n) return 0;
        cnt++;
        r = (r+1)%n;
        v[r] = value;
        return 1;
    }
    
    bool deleteFront() {
        if(cnt == 0) return 0;
        cnt--;
        l = (l+1)%n;
        return 1;
    }
    
    bool deleteLast() {
        if(cnt == 0) return 0;
        cnt--;
        r = (r-1+n)%n;
        return 1;
    }
    
    int getFront() {
        return cnt == 0 ? -1 : v[l];
    }
    
    int getRear() {
        return cnt == 0 ? -1 : v[r];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */