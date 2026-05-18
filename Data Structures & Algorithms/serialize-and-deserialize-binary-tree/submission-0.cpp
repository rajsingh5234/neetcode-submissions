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

class Codec {
public:

    vector<string> split(string &s, char ch){

        string temp = "";
        vector<string> ans;

        for(auto i : s){
            if(i == ch){
                ans.push_back(temp);
                temp = "";
            }
            else{
                temp += i;
            }
        }

        ans.push_back(temp);
        return ans;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            if(!node){
                ans += "x,";
            }
            else{
                string v = to_string(node->val);
                ans += v;
                ans += ",";
            }

            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }

        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        vector<string> arr = split(data, ',');

        if(arr[0] == "x") return NULL;

        TreeNode* root = new TreeNode(stoi(arr[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while(!q.empty()){
            
            auto node = q.front();
            q.pop();

            if(arr[i] == "x"){
                node->left = NULL;
            }
            else{
                node->left = new TreeNode(stoi(arr[i]));
                q.push(node->left);
            }
            i++;

            if(arr[i] == "x"){
                node->right = NULL;
            }
            else{
                node->right = new TreeNode(stoi(arr[i]));
                q.push(node->right);
            }
            i++;

        }

        return root;
    }
};
