### Implementation
- Use dp to store how much ways for a certain value
- To avoid permutation, every time use a value of coin, think it as looking for each amount of this coin value to make up the combination
- Only depend on the combinations before (only using previous coins or current coin) and add dp[current value - coin value] to dp[current value]
​
### Complexity
- O(n * m) in time
- O(m) in extra space
- n is the length of coins, m is the value of amount, also the size of dp
​
​
​
​
​