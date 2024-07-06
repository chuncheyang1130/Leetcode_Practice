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

        int node_num = 1;
        
        while (right != nullptr){
            if (left->next->val > left->val && left->next->val > right->val)
                crit_pt.push_back(node_num);
            else if (left->next->val < left->val && left->next->val < right->val)
                crit_pt.push_back(node_num);
            
            left = left->next;
            right = right->next;
            node_num++;
        }

        // for (int i = 0; i < crit_pt.size(); i++)
        //     cout << crit_pt[i] << " ";

        sort(crit_pt.begin(), crit_pt.end());

        for (int i = 1; i < crit_pt.size(); i++)
            ans[0] = min(ans[0], crit_pt[i] - crit_pt[i-1]);
        
        if (ans[0] == INT_MAX)
            ans[0] = -1;
        else ans[1] = crit_pt.back() - crit_pt.front();

        return ans;
    }
};