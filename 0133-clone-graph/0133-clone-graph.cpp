/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, map<int, Node*> &m) {
        if(!node || m[node->val]) return;
        m[node->val] = new Node(node->val);
        for(const auto &i: node->neighbors) {
            dfs(i, m);
            m[node->val]->neighbors.push_back(m[i->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        map<int, Node*> m;
        dfs(node, m);
        return m[node->val];
    }
};