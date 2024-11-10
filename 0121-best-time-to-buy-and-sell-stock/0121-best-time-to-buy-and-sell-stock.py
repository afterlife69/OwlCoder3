class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy, sell = 0 , 1
        days = len(prices)
        profit = 0
        while(sell < days):
            #print(buy , sell)
            profit = max(profit, prices[sell] - prices[buy])
            if prices[buy] > prices[sell]:
                buy = sell
            sell += 1
        return profit
        
        