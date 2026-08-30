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
    bool isEqual(TreeNode* node, TreeNode* subRoot) {
        if (!node || !subRoot) {
            return !subRoot && !node;
        }
        // if (!node && !subRoot) return true;   // Both are null
        // if (!node || !subRoot) return false;  // One is null, the other isn't
        return (node->val == subRoot->val) && isEqual(node->left, subRoot->left) &&
               isEqual(node->right, subRoot->right);
    }

   public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot) {
            return !subRoot && !root;
        }

        if (isEqual(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
