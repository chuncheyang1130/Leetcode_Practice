class Node{
public:
    int l, r, val;
    Node* left;
    Node* right;
    Node(int l, int r): l(l), r(r), left(nullptr), right(nullptr){};
};

class NumArray {
public:
    Node* root;
    vector<int> nums;
    int makeTree(Node* root){
        if(root->l == root->r){
            root->val = nums[root->l];
            return root->val;
        }
        
        int m = (root->l + root->r) / 2;
        root->left = new Node(root->l, m);
        root->right = new Node(m+1, root->r);
        root->val = makeTree(root->left) + makeTree(root->right);
        return root->val;
    }
    
    void modify(Node* root, int index, int val){
        if(root->l == root->r && root->l == index)
            root->val = val;
        else if(index <= root->left->r){
            modify(root->left, index, val);
            root->val = root->left->val + root->right->val;
        }else{
            modify(root->right, index, val);
            root->val = root->left->val + root->right->val;
        }
    }
    
    int search(Node* root, int left, int right){
        if(left == root->l && right == root->r)
            return root->val;
 
        int m = root->left->r;
        if(right <= m){
            return search(root->left, left, right);
        }else if(left > m){
            return search(root->right, left, right);
        }else{
            return search(root->left, left, m) + search(root->right, m+1, right);
        }
    }
        
    NumArray(vector<int>& nums) {
        this->root = new Node(0, nums.size()-1);
        this->nums = nums;
        int sum = makeTree(this->root);
    }
    
    void update(int index, int val) {
        modify(this->root, index, val);
    }
    
    int sumRange(int left, int right) {
        return search(root, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */