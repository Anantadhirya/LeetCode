/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node *tmp;
        Node *tmp2;
        Node *ans = new Node(-1);
        Node *tail = ans;
        tmp = head;
        vector<Node*> v;
        while(tmp) {
            v.push_back(tmp);
            tail->next = new Node(tmp->val);
            tail->next->random = tmp->random;
            tail = tail->next;
            tmp2 = tmp->next;
            tmp->next = tail;
            tmp = tmp2;
        }
        ans = ans->next;
        tail = ans;
        while(tail) {
            if(tail->random) tail->random = tail->random->next;
            tail = tail->next;
        }
        for(int i = 0; i+1 < v.size(); i++) {
            v[i]->next = v[i+1];
        }
        v.back()->next = NULL;
        return ans;
    }
};