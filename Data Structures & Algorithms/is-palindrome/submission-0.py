class Solution:
    def isAChar(self,c: char) -> bool:
        return (ord(c)>=ord('A') and ord(c)<=ord('Z')) or (ord(c)>=ord('a') and ord(c)<=ord('z')) or (ord(c)>=ord('0') and ord(c)<=ord('9'))
    def isPalindrome(self, s: str) -> bool:
        i = 0
        j = len(s)-1
        while i<len(s) and not self.isAChar(s[i]):
            i+=1
        while j>=0 and not self.isAChar(s[j]):
            j-=1
           # print(j,s[j])

        while i!=j or i<j:
            if s[i].lower()!=s[j].lower():
                #print('[',s[i],'] [',s[j],']',i,j)
                return False
            i+=1
            j-=1
            while i<len(s) and not self.isAChar(s[i]):
                i+=1
            while j>=0 and not self.isAChar(s[j]):
                j-=1
    
        return True