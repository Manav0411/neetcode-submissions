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
    void helper(vector<int>&prev, TreeNode* root){
        if(root == NULL) return;

        helper(prev,root->left);
        prev.push_back(root->val);
        helper(prev,root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;
        vector<int> pre;
        helper(pre,root);
        return pre[k-1];
    }
};
