class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True
            
        canReach = set()
        canReach.add(len(nums)-1)
        for i in range(len(nums)-2,-1,-1):
            x = i+nums[i]
            if x in canReach:
                if i == 0:
                    return True
                canReach.add(i)

        return False