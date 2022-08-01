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
class BSTIterator {
public:
    TreeNode* root;
    stack<TreeNode*> order;
    
    BSTIterator(TreeNode* root) {
        this->root = root;
        TreeNode* cur = root;
        order.push(cur);
        while(cur->left != nullptr){
            cur = cur->left;
            order.push(cur);
        }
    }
    
    int next() {
        TreeNode* tmp = order.top();
        order.pop();
        TreeNode* cur = tmp;
        if(cur->right != nullptr){
            cur = cur->right;
            order.push(cur);
            while(cur->left != nullptr){
                cur = cur->left;
                order.push(cur);
            }
        }
        return tmp->val;
    }
    
    bool hasNext() {
        return !order.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */