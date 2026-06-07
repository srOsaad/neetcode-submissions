class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        array = [0]*26
        for x in s:
            array[ord(x)-ord('a')]+=1
        
        for x in t:
            array[ord(x)-ord('a')]-=1
            if array[ord(x)-ord('a')]<0:
                return False
        for x in array:
            if x>0:
                return False
        return True
        