### Implemenation
- Sort the array first, start from the smallest number, check the number in front of it could divide the current number
- Use a hash table to store how many different kinds of tree can be formed for each number
- If the number n can divide m, then check dp[n] and dp[m/n], the number of unique product binary tree is dp[n] * dp[n/m] (think as left tree times right tree)
​
### Complexity
- O(n^2) in time
- O(n) in extra space
​
​