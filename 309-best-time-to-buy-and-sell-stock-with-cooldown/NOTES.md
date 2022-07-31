### Implementation
- 2 vectors: buy and sell
- For buy vector, consider buying on that day or not on that day,
- Buy on that day: sell[i-2] (must cool down for 1 day) - prices[i]
- Not on that day: buy[i-1]
- Choose max
- For sell vector, consider selling on that day or not on that day
- Sell on that day: buy[i-1]+prices[i]
- Not on that day: sell[i-1]
- Choose max
- Return the last value of sell
​
### Complexity
- O(n) in time
- O(n) in extra space
​
​