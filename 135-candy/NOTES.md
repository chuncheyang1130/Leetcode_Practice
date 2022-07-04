### Implementation
- In the beginning, initialize each position to 1 candy
- Start from left to right, if the value of the position is bigger than the value on its left, add 1 candy to the position
- Then start from right to left, if the value of the position is bigger than the value on its right, add 1 candy to position
- The first step only looks for lines whose slope > 0 (increasing from left to right), and the second step only looks for linew whose slope < 0 (increasing from right to left)
- The minimum number of candy of certain position needs to pick the max between the value from the first step and second step (this keeps the value of "climax" correct and avoid negative number of local minimum)
​
### Complexity
- O(n) in time
- O(n) in space
​
​