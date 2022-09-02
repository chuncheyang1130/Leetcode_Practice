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
    int traverse(TreeNode* root){
        int total = 0;
        if(root->left != nullptr){
            if(root->left->val >= root->val)
                total++;
            else root->left->val = root->val;
            
            total += traverse(root->left);
        }
        if(root->right != nullptr){
            if(root->right->val >= root->val)
                total++;
            else root->right->val = root->val;
            
            total += traverse(root->right);
        }
        return total;
    }
    
    int goodNodes(TreeNode* root) {
        return 1 + traverse(root);
    }
};