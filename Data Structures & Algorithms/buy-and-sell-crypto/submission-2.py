class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_n = 0
        min_n = prices[0]

        profit = 0

        for x in prices :
            if x < min_n :
                min_n = x
            else:
                max_n = x
                x = max_n - min_n
                profit = x if x > profit else profit
        return profit