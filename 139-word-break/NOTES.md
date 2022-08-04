### Implementation
- Check if substr(0, len) can be found in dict, if found, then dp[len-1] = true
- Check if substr(i, i+len) can be found in dict, if found, then dp[i+len-1] = true
- len is the length of each string in dict, i is the starting position
​
### Complexity
- n is the length of s, m is the size of dict
- O(nm) in time
- O(n) in extra space
​
​