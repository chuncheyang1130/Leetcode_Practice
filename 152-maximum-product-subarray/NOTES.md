### Implementation
- In order to maintain the local max and local min, if meet number < 0, first swap local max and local min and then times the number and maintain
- Must be careful of 0 because if meet zero, we need to reset local max and local start from next number, so when maintaining local max and local min, we must compare with current number to see it previous product is 0
- Always update global max product
​
### Complexity
- O(n) in time
- O(1) in extra space
​
​