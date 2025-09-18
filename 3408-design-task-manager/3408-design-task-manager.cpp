class TaskManager {
public:
    priority_queue<array<int, 3>> pq;
    map<int, pair<int, int>> m;
    TaskManager(vector<vector<int>>& tasks) {
        for(const auto &i: tasks) {
            pq.push({i[2], i[1], i[0]});
            m[i[1]] = {i[2], i[0]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId, userId});
        m[taskId] = {priority, userId};
    }
    
    void edit(int taskId, int newPriority) {
        auto id = m[taskId].second;
        pq.push({newPriority, taskId, id});
        m[taskId] = {newPriority, id};
    }
    
    void rmv(int taskId) {
        m[taskId] = {-1, -1};
    }
    
    int execTop() {
        pair<int, int> tmp;
        while(!pq.empty()) {
            tmp = m[pq.top()[1]];
            if(pq.top()[0] != tmp.first) pq.pop();
            else break;
        }
        if(pq.empty()) return -1;
        m[pq.top()[1]] = {-1, -1};
        pq.pop();
        return tmp.second;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */