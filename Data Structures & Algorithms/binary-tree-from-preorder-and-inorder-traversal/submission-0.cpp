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
    int pre_idx = 0;
    unordered_map<int,int> indices; 
    TreeNode* dfs(vector<int>& pre, int l, int r){
        if(l > r) return nullptr;
        int rootval = pre[pre_idx++];
        TreeNode* root = new TreeNode(rootval);
        int mid = indices[rootval];

        root->left = dfs(pre, l, mid-1);
        root->right = dfs(pre, mid+1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& ino) {
        for(int i = 0; i < ino.size(); i++){
            indices[ino[i]] = i;
        }
        return dfs(pre, 0, ino.size()-1);
    }
};
