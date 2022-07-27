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
    vector<TreeNode*> order;
    void traverse(TreeNode* root){
        order.push_back(root);
        if(root->left != nullptr)
            traverse(root->left);
        if(root->right != nullptr)
            traverse(root->right);
    }
    
    void flatten(TreeNode* root){
        TreeNode* head = new TreeNode();
        TreeNode* cur = head;
        if(root != nullptr){
            traverse(root);
            for(int i = 0; i < order.size(); i++){
                cur->right = order[i];
                cur = cur->right;
                cur->left = nullptr;
            }
            cur->right = nullptr;
        }
    }
};