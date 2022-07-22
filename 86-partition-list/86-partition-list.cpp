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
    ListNode* partition(ListNode* head, int x) {
        ListNode* start = new ListNode(0, head);
        ListNode* cur = start;
        ListNode* newHead = new ListNode();
        ListNode* newCur = newHead;
        
        while(cur->next != nullptr){
            if(cur->next->val >= x){
                newCur->next = cur->next;
                newCur = newCur->next;
                cur->next = cur->next->next;
            }else{
                cur = cur->next;
            }
        }
        newCur->next = nullptr;
        cur->next = newHead->next;
        return start->next;
        
    }
};