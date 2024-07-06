/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, 0);
        ans[0] = INT_MAX;
        ans[1] = -1;

        ListNode* left = head;
        ListNode* right = head->next->next;

        vector<int> crit_pt;

        int left_pt = -1;
        int prev_pt = -1;

        int node_num = 1;
        
        while (right != nullptr){
            if (left->next->val > left->val && left->next->val > right->val){
                if (left_pt == -1)
                    left_pt = node_num;
                
                if (prev_pt != -1)
                    ans[0] = min(ans[0], node_num-prev_pt);

                prev_pt = node_num;
            }
            else if (left->next->val < left->val && left->next->val < right->val){
                if (left_pt == -1)
                    left_pt = node_num;

                if (prev_pt != -1)
                    ans[0] = min(ans[0], node_num-prev_pt);

                prev_pt = node_num;
            }
            
            left = left->next;
            right = right->next;
            node_num++;
        }
        
        if (ans[0] == INT_MAX)
            ans[0] = -1;
        else ans[1] = prev_pt - left_pt;

        return ans;
    }
};