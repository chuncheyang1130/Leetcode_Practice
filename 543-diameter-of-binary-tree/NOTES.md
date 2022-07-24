### Implementation
- Traverse the left and right subtree, find out the longest path of each subtree and the depth of left and right subtree
- Keep update the longest path of the subtree, there are 2 things that need to consider: longest path of left and right subtree, and the sum of left and right depth since it may updates the current longest path
​
### Complexity
- O(logn) in time
- O(logn) in extra space
​
​