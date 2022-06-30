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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = (l1->val + l2->val) / 10;
        ListNode* head = new ListNode( (l1->val + l2->val) % 10);
        ListNode* cur = head;
        
        l1 = l1->next;
        l2 = l2->next;
        
        while(l1 != nullptr || l2 != nullptr){
            if(l1 != nullptr && l2 != nullptr){
                cur->next = new ListNode( (l1->val + l2->val + carry) % 10);
                carry = (l1->val + l2->val + carry ) / 10;
                l1 = l1->next;
                l2 = l2->next;
            }else if(l1 == nullptr){
                cur->next = new ListNode( (l2->val + carry) % 10);
                carry = (l2->val + carry) / 10;
                l2 = l2->next;
            }else if(l2 == nullptr){
                cur->next = new ListNode( (l1->val + carry) % 10);
                carry = (l1->val + carry) / 10;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        
        if(carry)
            cur->next = new ListNode(carry);
        
        return head;
    }
};