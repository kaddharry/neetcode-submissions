class Solution {
public:
    int ans;
    int counter;

    bool helper(TreeNode* node) {
        if (!node)
            return true;   // Keep searching

        // Search left subtree
        if (!helper(node->left))
            return false;

        // Visit current node
        if (counter == 0) {
            ans = node->val;
            return false;   // Found it, stop everything
        }
        counter--;

        // Search right subtree
        if (!helper(node->right))
            return false;

        return true;        // Didn't find it in this subtree
    }

    int kthSmallest(TreeNode* root, int k) {
        counter = k - 1;
        helper(root);
        return ans;
    }
};