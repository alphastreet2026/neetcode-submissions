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
    int getH(TreeNode* root){
        if (!root){
            return 0;
        }

        int left = getH(root->left);
        int right =  getH(root->right);
        if (left == -1 || right == -1){
            return -1;
        }
        if (abs(left-right) > 1){
            return -1;
        }
        return 1 + max(left, right);
    }

public:
    bool isBalanced(TreeNode* root) {
        int h = getH(root);
        return h == -1 ? false : true;    
    }
};
