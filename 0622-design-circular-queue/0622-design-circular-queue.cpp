class MyCircularQueue {
public:
    int k, l, sz;
    vector<int> v;
    MyCircularQueue(int k) {
        this->k = k;
        v.resize(k);
        l = 0;
        sz = 0;
    }
    
    bool isEmpty() {
        return sz == 0;
    }
    
    bool isFull() {
        return sz == k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return 0;
        sz++;
        v[(l+sz-1)%k] = value;
        return 1;
    }
    
    bool deQueue() {
        if(isEmpty()) return 0;
        sz--;
        l = (l+1)%k;
        return 1;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return v[l];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return v[(l+sz-1)%k];
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */