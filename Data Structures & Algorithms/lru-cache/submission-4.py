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
        self.debug = False

    def printHead(self) -> None:
        if not self.debug:
            return;
        point = self.head
        print('Head: ')
        while point:
            print(point.value,end=', ')
            point = point.next
        print('Self.current now:',self.current.value)
        print('\n')

    def get(self, key: int) -> int:
        if self.debug:
            print('GET',key)
        if self.filled == 0:
            return -1
            
        if self.head.key == key:
            x = self.head.value
            if self.filled != 1:
                self.head = self.head.next
                self.current.next = node(key,x)
                self.current = self.current.next
            self.printHead()
            return x
        elif self.filled == 1:
            return -1
        
        if self.current.key == key:
            return self.current.value
        elif self.filled == 2:
            return -1
    
        prv = self.head
        point = self.head.next
        while point!=None:
            if point.key == key:
                prv.next = point.next
                self.current.next = node(key,point.value)
                self.current = self.current.next
                self.printHead()
                return point.value
            prv = point
            point = point.next
        return -1

    def put(self, key: int, value: int) -> None:
        if self.debug: 
            print("PUT",key,(value if key!=value else ''))
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
                prv = None
                while point!= None:
                    if point.key == key:
                        if prv == None:
                            if self.filled == 1:
                                point.value = value
                            else:
                                self.head = self.head.next
                                self.current.next = node(key,value)
                                self.current = self.current.next
                        else:
                            if point.next==None:
                                point.value = value
                            else:
                                prv.next=point.next
                                self.current.next = node(key,value)
                                self.current = self.current.next
                        return
                    prv = point
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
        self.printHead()
