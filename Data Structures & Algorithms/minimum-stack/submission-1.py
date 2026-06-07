class MinStack:
    nums = []
    def __init__(self):
        self.nums = []

    def push(self, val: int) -> None:
        print("push be: ",self.nums)
        self.nums.append(val)
        print("push af: ",self.nums)

    def pop(self) -> None:
        print("pop be: ",self.nums)
        if len(self.nums)>0:
            self.nums.pop(len(self.nums)-1)
        print("pop af: ",self.nums)

    def top(self) -> int:
        print("top: ",self.nums)
        if len(self.nums)>0:
            return self.nums[len(self.nums)-1]

    def getMin(self) -> int:
        print("get min ",self.nums)
        if len(self.nums) == 0:
            return -2
        x = self.nums[0]
        for i in self.nums:
            x = min(x,i)
        print(x)
        return x