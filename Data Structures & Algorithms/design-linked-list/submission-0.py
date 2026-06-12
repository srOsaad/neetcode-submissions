class node:
    def __init__(self, val : int):
        self.value = val
        self.next = None

class MyLinkedList:

    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def get(self, index: int) -> int:
        #j = self.head
        #while j!=None:
        #    print(j.value,end=', ' if j.next != None else '\n')
        #    j=j.next
        #print('--------------------')
        #print('get',index,self.size)
        if index>self.size:
            return -1
        
        point = self.head
        while index>0:
            point=point.next
            index-=1
        
        return point.value

    def addAtHead(self, val: int) -> None:
        
        if self.size == 0:
            self.head = node(val)
            self.tail = self.head
        
        else:
            point = node(val)
            point.next = self.head
            self.head = point
        self.size +=1
        

    def addAtTail(self, val: int) -> None:
        if self.size == 0:
            self.head = node(val)
            self.tail = self.head
        
        else:
            point = node(val)
            self.tail.next = point
            self.tail = point
        self.size+=1

    def addAtIndex(self, index: int, val: int) -> None:
        if index>self.size:
            return
        
        if index == 0:
            self.addAtHead(val)
        elif index == self.size:
            self.addAtTail(val)
        else:
            point = self.head
            for i in range(index-1):
                point=point.next
            x = point.next
            point.next = node(val)
            point = point.next
            point.next = x
            self.size += 1

    def deleteAtIndex(self, index: int) -> None:
        if index>=self.size:
            return
        
        if index == 0:
            if self.size == 1:
                self.head = None
                self.tail = None
            self.head = self.head.next
        
        point = self.head
        for i in range(index-1):
            point = point.next
        
        if index == self.size-1:
            point.next = None
            tail = point
        else:
            x = point.next
            point.next = point.next.next
            x.next = None

        self.size-=1


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)