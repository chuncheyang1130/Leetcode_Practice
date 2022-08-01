### Implementation
- Use the idea of dfs, keep searching if there are left nodes, store the path in stack
- When looking for the next smallest number, pop the top of stack and check if it has right child
- If yes, then find the path to the most left leaf of the right subtree
- If no, no need to do anything
- Return the value of the node pop from the stack
​
### Complexity
- O(logn) in next function because update stack requires traversing
- O(1) in hasNext because only need to return whether the stack is empty
​
​