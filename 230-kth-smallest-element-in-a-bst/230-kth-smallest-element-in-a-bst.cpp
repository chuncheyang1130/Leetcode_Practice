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
    int ans;
    int BS(TreeNode* root, int rank, int k){
        if(root->left == nullptr && root->right == nullptr){
            if(rank == k){
                this->ans = root->val;
                return -1;
            }else return rank+1;
        }
        
        int new_rank = rank;
        if(root->left != nullptr){
            new_rank = BS(root->left, rank, k);
            if(new_rank == -1)
                return -1;
        }
        
        if(new_rank == k){
            this->ans = root->val;
            return -1;
        }else new_rank++;
        
        if(root->right != nullptr)
            new_rank = BS(root->right, new_rank, k);
        return new_rank;
    }
    int kthSmallest(TreeNode* root, int k) {
        int tmp = BS(root, 1, k);
        return this->ans;
    }
};