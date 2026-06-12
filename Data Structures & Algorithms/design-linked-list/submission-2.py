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
        if index < 0 or index >= self.size:
            return -1

        point= self.head

        
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
        if index<0 or index>self.size:
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
        if index < 0 or index >= self.size:
            return
        
        if index == 0:
            if self.size == 1:
                self.head = None
                self.tail = None
            else:
                self.head = self.head.next
            self.size-=1
            return
        
        point = self.head
        for _ in range(index-1):
            point = point.next
             
        if index == self.size-1:
            point.next = None
            self.tail = point
        else:
            x = point.next
            point.next = point.next.next
            x.next = None

        self.size-=1
