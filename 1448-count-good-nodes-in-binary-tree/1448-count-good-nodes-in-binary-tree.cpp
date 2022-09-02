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
    void traverse(TreeNode* root, int& total){
        if(root->left != nullptr){
            if(root->left->val >= root->val)
                total++;
            else root->left->val = root->val;
            
            traverse(root->left, total);
        }
        if(root->right != nullptr){
            if(root->right->val >= root->val)
                total++;
            else root->right->val = root->val;
            
            traverse(root->right, total);
        }
    }
    
    int goodNodes(TreeNode* root) {
        int total = 1;
        traverse(root, total);
        return total;
    }
};