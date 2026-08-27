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
    void invert(TreeNode* node) {
        if (!node){
            return;
        }
        auto leftNode = node->left;
        node->left = node->right;
        node->right = leftNode;
        invert(node->left);
        invert(node->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root){
            return nullptr;
        }

        invert(root);
        return root;
    }
};
