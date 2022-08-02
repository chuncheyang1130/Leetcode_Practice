### Implementation
- Start from the end of the string, check if substring can be decoded
- Two cases
- If the character itself can be decoded, then add the answer of dp[i+1] to dp[i] since we already know how many decoded ways are there for the substring behind
- If the character and the next character can be decoded as 2 digits, then add the value of dp[i+2] to dp[i]
​
### Complexity
- O(n) in time
- O(n) in extra space
​
​