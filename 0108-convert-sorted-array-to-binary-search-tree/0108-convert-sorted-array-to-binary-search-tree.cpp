/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* &curr, int l, int r, vector<int> &nums) {
        if(l > r) return;
        int mid = (l+r)/2;
        curr = new TreeNode(nums[mid]);
        solve(curr->left, l, mid-1, nums);
        solve(curr->right, mid+1, r, nums);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* ret;
        solve(ret, 0, nums.size()-1, nums);
        return ret;
    }
};