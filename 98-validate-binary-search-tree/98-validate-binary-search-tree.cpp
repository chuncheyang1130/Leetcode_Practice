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
    bool isValidBST(TreeNode* root, unordered_map<int, pair<int,int>>& table){
        table[root->val] = pair<int, int>({root->val, root->val});
        
        if(root->left == nullptr && root->right == nullptr){
            table[root->val] = pair<int, int>({root->val, root->val});
            return true;
        }
        
        if(root->right != nullptr){
            bool valid = isValidBST(root->right, table);
            if(!valid || root->val >= table[root->right->val].first)
                return false;
            table[root->val].second = table[root->right->val].second;
        }
        
        if(root->left != nullptr){
            bool valid = isValidBST(root->left, table);
            if(!valid || root->val <= table[root->left->val].second)
                return false;
            table[root->val].first = table[root->left->val].first;
        }
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        unordered_map<int, pair<int, int>> table;
        return isValidBST(root, table);
    }
};