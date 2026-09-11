# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        count = 0
        current = head
        
        while current != None:
            count+=1
            current = current.next
        
        if count == n:
            head = head.next
            return head

        count -= (n+1)

        current = head

        while count>0:
            count-=1
            current = current.next

        hold = current.next

        current.next = None

        if hold.next != None:
            current.next = hold.next

        return head