class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        n = len(nums)
        rnums = [0]*(n*2)
        for i in range(len(rnums)):
            if i<len(nums):
                rnums[i] = nums[i]
                continue
            rnums[i] = nums[i-n]
        return rnums