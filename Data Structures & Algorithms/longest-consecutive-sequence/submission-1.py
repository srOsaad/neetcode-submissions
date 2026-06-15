class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ans = 0
        nums = sorted(nums)
        #print(nums)
        current = None
        count = 0
        last = None
        for x in nums:
            if current == None:
                current = x
                last = x
                count+=1
            elif x == last:
                continue
            else:
                last = x
                current+=1
                if current == x:
                    count+=1
                else:
                    current = x
                    ans = count if count>ans else ans
                    count = 1
                    #print(ans)
        ans = count if count>ans else ans
        return ans;