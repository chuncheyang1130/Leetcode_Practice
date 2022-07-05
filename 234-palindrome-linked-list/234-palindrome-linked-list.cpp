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
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head->next, *slow = head;
        vector<int> order;
        while(fast != nullptr){
            order.push_back(slow->val);
            if(fast->next == nullptr)
                break;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        for(int i = order.size()-1; i >= 0; i--){
            slow = slow->next;
            if(slow->val != order[i])
                return false;
        }
        return true;
    }
};