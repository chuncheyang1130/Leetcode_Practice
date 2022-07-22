### Implementation
- Calculate current max value of left seat (leftSeatMaxValue, values[i-1]+i-1), and add to current right seat value (values[i]-i), maintain maximum result
- The implementation is quite similar to maximum subarray
​
### Complexity
- O(n) in time
- O(1) in extra space
​
​