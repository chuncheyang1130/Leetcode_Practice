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
    void makeTree(vector<int>& nums, TreeNode* root, int left, int right){
        if(left == right){
            root->val = nums[left];
            return;
        }
        
        int m = (left+right)/2;
        root->val = nums[m];
        if(m != left){
            root->left = new TreeNode();
            makeTree(nums, root->left, left, m-1);
        }
        root->right = new TreeNode();
        makeTree(nums, root->right, m+1, right);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = new TreeNode();
        makeTree(nums, root, 0, nums.size()-1);
        return root;
    }
};