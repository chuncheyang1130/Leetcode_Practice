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
    bool traverse(TreeNode* l, TreeNode* r){
        bool sym = false;
        if(l->left != nullptr && r->right != nullptr)   
            sym = traverse(l->left, r->right);
        else if(l->left == nullptr && r->right == nullptr)
            sym = true;
        
        if(!sym)
            return false;
        
        sym = false;
        if(l->right != nullptr && r->left != nullptr)
            sym = traverse(l->right, r->left);
        else if(l->right == nullptr && r->left == nullptr)
            sym = true;
        
        if(!sym)
            return false;
        
        return (l->val == r->val);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)
            return true;
        else if((root->left == nullptr && root->right != nullptr) || (root->left != nullptr && root->right == nullptr))
            return false;
        return traverse(root->left, root->right);
    }
};