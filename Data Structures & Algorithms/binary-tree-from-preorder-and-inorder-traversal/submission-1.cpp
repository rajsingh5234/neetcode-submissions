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
    int findPos(int s, int e, int x, vector<int>&inorder){
        for(int i=s; i<=e; i++){
            if(inorder[i] == x) return i;
        }
        return -1;
    }

    TreeNode* solve(int s, int e, int &i, vector<int>& preorder, vector<int>& inorder){

        if(s > e) return NULL;

        TreeNode* root = new TreeNode(preorder[i]);
        int pos = findPos(s, e, preorder[i], inorder);
        i++;
        root->left = solve(s, pos-1, i, preorder, inorder);
        root->right = solve(pos+1, e, i, preorder, inorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int s = 0, e = n-1, i = 0;
        return solve(s, e, i, preorder, inorder);
    }
};
