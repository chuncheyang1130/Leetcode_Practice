### Implementation
- First do prefix sum just like the implemenation of maximum subarray
- Use a hash table to store how many times a value of sum has appeared before
- Ex. [1, 1, 1], target = 2,  then when sum up to second element, check how many prefix sum is equal to 2-2=0 so far, so 0 only appears once so far (start from no number)
​
### Complexity
- O(n) in time
- O(n) in extra space
​
​