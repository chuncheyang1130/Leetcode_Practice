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
    bool isValidBST(TreeNode* root, long long m, long long M){
        if(root->right != nullptr){
            bool valid = isValidBST(root->right, (long long)root->val, M);
            if(!valid)
                return false;
        }
        
        if(root->left != nullptr){
            bool valid = isValidBST(root->left, m, (long long)root->val);
            if(!valid)
                return false;
        }
        
        if(root->val > m && root->val < M)
            return true;
        else return false;
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};