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
        unordered_map<int, int> parent; 
        unordered_map<int, TreeNode*> tree;

        for (int i = 0; i < descriptions.size(); i++){
            int parNum = descriptions[i][0];
            int chdNum = descriptions[i][1];

            if (parent.find(parNum) == parent.end())
                parent[parNum] = 0;

            if (tree.find(parNum) == tree.end())
                tree[parNum] = new TreeNode(parNum);
            

            if (tree.find(chdNum) == tree.end())
                tree[chdNum] = new TreeNode(chdNum);

            if (descriptions[i][2])
                tree[parNum]->left = tree[chdNum];
            else tree[parNum]->right = tree[chdNum];

            parent[chdNum] = parNum;
        }

        TreeNode* root;
        for (auto it = parent.begin(); it != parent.end(); it++){
            if (it->second == 0){
                root = tree[it->first];
                break;
            }
        }

        return root;
    }
};