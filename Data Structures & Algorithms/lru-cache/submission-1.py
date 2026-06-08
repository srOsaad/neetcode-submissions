class node :
    def __init__(self,key, data):
        self.key = key
        self.value = data 
        self.next = None 

class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.filled = 0
        self.head = None
        self.current = None

    def get(self, key: int) -> int:
        if self.filled == 0:
            return -1

        if self.head.key == key:
            x = self.head.value
            if self.filled != 1:
                self.head = self.head.next
                self.current.next = node(key,x)
                self.current = self.current.next
            return x
        
        if self.current.key == key:
            return self.current.value
    
        prv = self.head
        point = prv.next
        while point!=None:
            if point.key == key:
                prv.next = point.next
                current.next = node(key,point.value)
                current = current.next
                return point.value
            point = point.next
        return -1

    def put(self, key: int, value: int) -> None:
        if self.filled == 0:
            self.head = node(key,value)
            self.current = self.head
            self.filled = 1
        
        elif self.filled == self.cap:
            if self.cap == 1:
                self.head = node(key,value)
                self.current = self.head
            else:
                point = self.head
                while point!= None:
                    if point.key == key:
                        point.value = value
                        return
                    point = point.next
                self.head = self.head.next
                self.current.next = node(key,value)
                self.current = self.current.next
                
        else:
            point = self.head
            while point!= None:
                if point.key == key:
                    point.value = value
                    return
                point = point.next
            self.current.next = node(key,value)
            self.current = self.current.next
            self.filled+=1
