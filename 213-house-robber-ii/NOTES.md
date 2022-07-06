### Implementation
- Divide into 3 case: house 0 & last is not robbed, house 0 is robbed (last house must not be robbed) , and last is robbed (house 0 must not be robbed)
- Others are similar to house robber I, update cur_rob_max by choosing the max between the maximum amout of money if previous house is robbed or previous house is not robbed
​
### Complexity
- O(n) in time
- O(n) in extra space
​
​
