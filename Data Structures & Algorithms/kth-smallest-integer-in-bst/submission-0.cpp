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
    int ans;
    int counter;
    void helper(TreeNode* node){
        if(!node) return;

        helper(node->left);
        if(counter == 0){
            ans = node->val;
            counter = INT_MAX;
            return;
        }
        else counter--;
        helper(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        ans = 0;
        counter = k - 1;
        helper(root);
        return ans;
    }
};
