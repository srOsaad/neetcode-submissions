class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        MIN = None
        PROFIT = 0
        for x in prices:
            if MIN == None or x<MIN:
                MIN = x
            else:
                temp = x - MIN
                PROFIT = temp if temp > PROFIT else PROFIT
        return PROFIT
