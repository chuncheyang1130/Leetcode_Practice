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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;
        
        int len = 1;
        ListNode *cur = head, *end = head;
        while(end->next != nullptr){
            end = end->next;
            len++;
        }
        
        len /= 2;
        while(len--){
            end->next = cur->next;
            end = end->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        
        end->next = nullptr;
        return head;
    }
};