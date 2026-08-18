class Solution {
public:

    int height(TreeNode* root) {

        // Empty tree has height 0
        if (root == nullptr)
            return 0;

        // Height of left subtree
        int left = height(root->left);

        // If left subtree is unbalanced
        if (left == -1)
            return -1;

        // Height of right subtree
        int right = height(root->right);

        // If right subtree is unbalanced
        if (right == -1)
            return -1;

        // Check current node
        if (abs(left - right) > 1)
            return -1;

        // Return height of current tree
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};