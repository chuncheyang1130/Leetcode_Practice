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
    
    int depth(TreeNode* root){
        if(root->left == nullptr && root->right == nullptr)
            return 1;
        
        int left_depth = 0, right_depth = 0;
        if(root->left != nullptr)
            left_depth = depth(root->left);
        if(root->right != nullptr)
            right_depth = depth(root->right);
        
        if(left_depth == -1 || right_depth == -1 || abs(left_depth-right_depth) > 1)
            return -1;
        else return max(right_depth, left_depth) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        int d = depth(root);
        if(d == -1)
            return false;
        else return true;
    }
};