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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(), *ret=ans;
        while(list1 && list2) {
            ListNode* t = nullptr;
            if(list1->val<list2->val) {
                t=list1;
                list1=list1->next;
            }
            else{
                t=list2;
                list2=list2->next;
            }
            ans->next = t;
            ans = ans->next;
        }

        if(list1) ans->next = list1;
        if(list2) ans->next = list2;

        ans=ret->next;
        return ans;
    }
};
