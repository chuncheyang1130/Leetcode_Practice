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
    TreeNode* traverse(TreeNode* root){
        TreeNode *rightLeaf = nullptr, *leftLeaf = nullptr;
        //cout << root->val << endl;
        if(root->left == nullptr && root->right == nullptr)
            return root;
        
        if(root->right != nullptr){
            rightLeaf = traverse(root->right);
        }
        if(root->left != nullptr){
            leftLeaf = traverse(root->left);
            if(rightLeaf != nullptr){
                leftLeaf->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }else{
                root->right = root->left;
                rightLeaf = leftLeaf;
                root->left = nullptr;
            }
        }
        return rightLeaf;
    }
    
    void flatten(TreeNode* root){
        if(root != nullptr)
            TreeNode* tmp = traverse(root);
    }
};