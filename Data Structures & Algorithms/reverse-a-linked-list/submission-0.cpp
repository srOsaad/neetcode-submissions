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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* pre=head, *aft = nullptr;
        head=head->next;
        pre->next = nullptr;
        while(head) {
            //cout<<pre->val<<' '<<head->val<<'\n';
            aft=head->next;
            head->next=pre;
            pre=head;
            head=aft;
        }
        return pre;
    }
};
