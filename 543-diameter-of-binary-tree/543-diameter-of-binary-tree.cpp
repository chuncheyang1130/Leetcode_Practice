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
    pair<int,int> trav(TreeNode* root){
        int left = 0, right = 0;
        int M = 0;
        if(root->left != nullptr){
            pair<int, int> tmp = trav(root->left);
            left = tmp.first+1;
            M = max(M, tmp.second);
        }
        if(root->right != nullptr){
            pair<int, int> tmp = trav(root->right);
            right = tmp.first+1;
            M = max(M, tmp.second);
        }
        return make_pair(max(right, left), max(M, left+right));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ans = trav(root);
        return ans.second;
    }
};