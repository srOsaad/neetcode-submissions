class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        rnums = []
        for i in range(2):
            for j in range(len(nums)):
                rnums.append(nums[j])
        return rnums