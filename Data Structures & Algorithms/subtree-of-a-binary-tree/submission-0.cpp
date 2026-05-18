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

    bool solve(TreeNode* &a, TreeNode* &b){
        if(!a && !b) return 1;
        if(!a && b) return 0;
        if(a && !b) return 0;

        if(a->val != b->val) return 0;

        return solve(a->left, b->left) && solve(a->right, b->right);

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(!subRoot) return 1;
        if(!root) return 0;
        
        if(solve(root, subRoot)) return 1;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
