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
    int traverse(TreeNode* root, unordered_map<long long, int> table, long long curSum, int targetSum){
        int count = 0;
        curSum += root->val;
        if(table.find(curSum-targetSum) != table.end())
            count += table[curSum-targetSum];
        table[curSum]++;
        
        if(root->left != nullptr)
            count += traverse(root->left, table, curSum, targetSum);
        if(root->right != nullptr)
            count += traverse(root->right, table, curSum, targetSum);
        
        return count;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return 0;
        unordered_map<long long, int> table;
        table[0] = 1;
        int count = traverse(root, table, 0, targetSum);
        return count;
    }
};