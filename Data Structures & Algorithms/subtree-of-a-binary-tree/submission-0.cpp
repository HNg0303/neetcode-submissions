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
    bool areIdentical(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return true;
        }
        if (!root1 || !root2) {
            return false;
        }
        return (root1->val == root2->val && areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // This problem gives us two tree nodes, and ask us to determine if one is the subtree of other.
        // We can do this by comparing preorder traversal of the two trees. The reason we use preorder traversal was because of the preorder traversal
        // give us the true representation of a tree.
        if (!subRoot) return true;
        if (!root) return false;

        if (areIdentical(root, subRoot)) return true;
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};
