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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* cur = head;
        while(cur != nullptr){
            len++;
            cur = cur->next;
        }
        
        cur = head;
        if(len == n){
            head = head->next;
            return head;
        }
        while(len > n+1){
            cur = cur->next;
            len--;
        }
        
        cur->next = cur->next->next;
        return head;
    }
};