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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *slow = head, *fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* new_head = slow->next;
        slow->next = nullptr;
        
        head = sortList(head);
        new_head = sortList(new_head);
        
        ListNode *head_cur = head, *new_head_cur = new_head, *sorted = new ListNode(), *sorted_cur = sorted;
        while(head_cur != nullptr || new_head_cur != nullptr){
            if(head_cur == nullptr){
                sorted_cur->next = new_head_cur;
                break;
            }else if(new_head_cur == nullptr){
                sorted_cur->next = head_cur;
                break;
            }else if(head_cur->val <= new_head_cur->val){
                sorted_cur->next = head_cur;
                sorted_cur = sorted_cur->next;
                head_cur = head_cur->next;
            }else if(head_cur->val > new_head_cur->val){
                sorted_cur->next = new_head_cur;
                sorted_cur = sorted_cur->next;
                new_head_cur = new_head_cur->next;
            }
        }
        sorted = sorted->next;
        
        return sorted;
    }
};