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
    int diameter(TreeNode* node, int& maxH){
        if (!node){
            return 0;
        }

        int left = diameter(node->left, maxH);
        int right = diameter(node->right, maxH);
        
        maxH = max(maxH, left + right);
        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxH = 0;
        diameter(root, maxH);
        return maxH;
    }
};
