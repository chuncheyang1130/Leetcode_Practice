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
    void traverse(TreeNode* root, int targetSum, int curSum, vector<vector<int>>& path, vector<int> curPath){
        curSum += root->val;
        curPath.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(curSum == targetSum){
                path.push_back(curPath);
                return;
            }
        }
        
        if(root->left != nullptr)
            traverse(root->left, targetSum, curSum, path, curPath);
        
        if(root->right != nullptr)
            traverse(root->right, targetSum, curSum, path, curPath);
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> path;
        if(root == nullptr)
            return path;
        vector<int> tmp;
        traverse(root, targetSum, 0, path, tmp);
        return path;
    }
};