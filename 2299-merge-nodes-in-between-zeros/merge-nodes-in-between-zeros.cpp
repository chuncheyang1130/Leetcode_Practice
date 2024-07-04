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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* cur = head->next;
        ListNode* new_head = nullptr;
        ListNode* new_cur = nullptr;

        int count = 0;
        
        while (cur != nullptr){
            if (cur->val == 0){
                count = 0;
                cur = cur->next;
            }else{
                count += cur->val;
                if (cur->next->val == 0){
                    if (new_head == nullptr){
                        new_head = cur;
                        new_cur = new_head;
                        new_cur->val = count;
                    }else {
                        new_cur->next = cur;
                        new_cur = new_cur->next;
                        new_cur->val = count;
                    }
                }
                cur = cur->next;
            }
        }

        new_cur->next = nullptr;
        return new_head;
    }
};