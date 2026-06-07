class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        zero_at = -1
        pdct = 1
        ret = [0]*len(nums)
        for i in range(0,len(nums)):
            if nums[i] == 0:
                if zero_at > -1:
                    return ret
                zero_at = i
            else:
                pdct*=nums[i]
            
        if zero_at > -1:
            ret[zero_at] = pdct
        else:
            for i in range(0,len(nums)):
                ret[i]=int(pdct/nums[i])
        return ret
        
            