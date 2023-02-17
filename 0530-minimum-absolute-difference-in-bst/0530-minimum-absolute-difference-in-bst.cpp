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
    vector<int> vec;
    void inOrder(TreeNode* root){
        if(root->left != nullptr)
            inOrder(root->left);

        vec.push_back(root->val);
        if(root->right != nullptr)
            inOrder(root->right);

    }
    int getMinimumDifference(TreeNode* root) {
        if(root != nullptr)
            inOrder(root);
        
        int m = 1e9;
        for(int i = 0; i < vec.size()-1; i++){
            m = min(vec[i+1] - vec[i], m);
        }

        return m;
    }
};