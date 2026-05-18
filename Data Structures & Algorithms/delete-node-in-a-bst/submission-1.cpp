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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root) return NULL;

        if(root->val == key){
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            else if(root->left && !root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else if(!root->left && root->right){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else{
                TreeNode* temp = root->right;
                int v = INT_MAX;
                while(temp){
                    v = min(v, temp->val);
                    temp = temp->left;
                }

                root->val = v;
                root->right = deleteNode(root->right, v);
                return root;
            }
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        }
        else{
            root->right = deleteNode(root->right, key);
            return root;
        }

        return NULL;
    }
};