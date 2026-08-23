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

class Codec {
public:
    void serialize(TreeNode* root, string& s) {
        if (root == NULL) {
            s += "null,";
            return;
        }
        s += to_string(root->val) + ",";

        serialize(root->left, s);
        serialize(root->right, s);
    }
    string serialize(TreeNode* root) {
        string s = "";
        serialize(root, s);
        return s;
    }

    TreeNode* helper(vector<string>& tokens, int& index) {
    if (tokens[index] == "null") {
        index++;
        return NULL;
    }

    TreeNode* root = new TreeNode(stoi(tokens[index]));
    index++;

    root->left = helper(tokens, index);
    root->right = helper(tokens, index);

    return root;
}
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        int i = 0;
        while(i<data.length()){
            string s = "";
            while(data[i]!=',' && i < data.length()){
                s+=data[i];
                i++;
            }
            tokens.push_back(s);
            i = i+1;
        }
        int idx = 0;
        return helper(tokens,idx);
    }
};

