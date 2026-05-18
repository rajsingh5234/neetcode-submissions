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

    int solve(TreeNode* &root, int &ans){
        if(!root) return -1001;
        
        int left = solve(root->left, ans);
        int right = solve(root->right, ans);
        int v = root->val;

        int op1,op2,op3,op4;

        op1 = v;
        op2 = v+left;
        op3 = v+right;
        op4 = v+left+right;

        int res = max(max(op1, op2), max(op3, op4));

        ans = max(ans, res);

        return max(op1, max(op2,op3));
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int v = solve(root, ans);

        return max(v, ans);
    }
};
