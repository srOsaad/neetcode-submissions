class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)-1):
            t = target - nums[i]
            for l in range(i+1,len(nums)):
                if nums[l]==t:
                    return [i,l]
        return [-1,-1]