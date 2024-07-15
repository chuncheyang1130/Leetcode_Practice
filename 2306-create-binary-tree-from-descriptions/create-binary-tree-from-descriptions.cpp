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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        vector<int> parent(1e5+1, -1);  
        map<int, TreeNode*> tree;
        int parNum = -1, chdNum = -1;

        for (int i = 0; i < descriptions.size(); i++){
            parNum = descriptions[i][0];
            chdNum = descriptions[i][1];

            if (parent[parNum] == -1)
                parent[parNum] = 0;

            if (tree.find(parNum) == tree.end()){
                TreeNode* node = new TreeNode(parNum);
                tree[parNum] = node;
            }

            if (tree.find(chdNum) == tree.end()){
                TreeNode* node = new TreeNode(chdNum);
                tree[chdNum] = node;
            }

            if (descriptions[i][2])
                tree[parNum]->left = tree[chdNum];
            else tree[parNum]->right = tree[chdNum];

            parent[chdNum] = parNum;
        }

        TreeNode* root;
        for (int i = 1; i < parent.size(); i++){
            if (parent[i] == 0){
                root = tree[i];
                break;
            }
        }

        return root;
    }
};