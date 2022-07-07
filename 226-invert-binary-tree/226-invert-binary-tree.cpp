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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return root;
        TreeNode* cur = root;
        if(root->left != nullptr && root->right != nullptr){
            cur = cur->right;
            root->right = invertTree(root->left);
            root->left = invertTree(cur);
        }else if(root->left != nullptr){
            root->right = invertTree(root->left);
            root->left = nullptr;
        }else if(root->right != nullptr){
            root->left = invertTree(root->right);
            root->right = nullptr;
        }
        return root;
    }
};