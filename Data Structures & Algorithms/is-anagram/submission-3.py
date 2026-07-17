class Solution:
    def cn(self, x) -> int:
        return ord(x)-ord('a')

    def isAnagram(self, s: str, t: str) -> bool:
        count = [0]*26

        for c in s:
            count[self.cn(c)]+=1
        
        for c in t:
            count[self.cn(c)]-=1
            if count[self.cn(c)]<0:
                return False
        
        for x in count:
            if x>0:
                return False
        
        return True