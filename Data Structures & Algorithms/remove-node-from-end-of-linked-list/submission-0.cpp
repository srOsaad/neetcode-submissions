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
        int count = 0;
        ListNode* current = head;
        while(current) {
            count++;
            current = current->next;
        }

        if(n==count) {
            head = head->next;
            return head;
        }

        count -= ++n;

        current = head;
        
        while(count) {
            current = current->next;
            count--;
        }
        
        ListNode* hold = current->next;
        current->next = nullptr;

        if(hold->next) {
            current->next = hold->next;
        }

        return head;
    }
};
