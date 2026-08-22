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
    TreeNode* build(vector<int>& preorder, int preStart, int inStart, int inEnd,
                    unordered_map<int, int>& pos) {
        if (inStart > inEnd) return NULL;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int rootIndex = pos[rootVal];
        int leftSize = rootIndex - inStart;

        root->left = build(preorder, preStart + 1, inStart, rootIndex - 1, pos);

        root->right = build(preorder, preStart + leftSize + 1, rootIndex + 1, inEnd, pos);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        return build(preorder, 0, 0, inorder.size() - 1, mpp);
    }
};
