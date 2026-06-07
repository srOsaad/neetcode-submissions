# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        ans = None
        point = None
        while list1!= None and list2!=None:
            add = ListNode()
            if list1.val<list2.val:
                add.val = list1.val
                if ans == None:
                    ans = add
                    point = ans
                else:
                    point.next = add
                    point = point.next
                list1 = list1.next

            else:
                add.val = list2.val
                if ans == None:
                    ans = add
                    point = ans
                else:
                    point.next = add
                    point = point.next
                list2 = list2.next
        
        if list1 != None:
            if ans == None:
                return list1
            point.next = list1
        
        if list2 != None:
            if ans == None:
                return list2
            point.next = list2
        
        return ans
