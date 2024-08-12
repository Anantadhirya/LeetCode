/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void solve(Node* root, int d, vector<Node*> &v) {
        if(!root) return;
        if(d >= v.size()) v.push_back(NULL);
        root->next = v[d];
        v[d] = root;
        solve(root->right, d+1, v);
        solve(root->left, d+1, v);
    }
    Node* connect(Node* root) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<Node*> v;
        solve(root, 0, v);
        return root;
    }
};