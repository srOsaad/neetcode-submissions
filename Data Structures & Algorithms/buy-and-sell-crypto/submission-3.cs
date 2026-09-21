public class Solution {
    public int MaxProfit(int[] prices) {
        int min_p = prices[0], max_p = -1, profit = 0, tm;
        for(int i=0; i<prices.Length; i++) {
            if(max_p<prices[i]) {
                max_p = prices[i];
            }
            if(min_p>prices[i]) {
                min_p = prices[i];
                max_p = prices[i];
            }

            tm = max_p - min_p;

            profit = tm>profit ? tm : profit;
        }

        return profit;
    }
}
