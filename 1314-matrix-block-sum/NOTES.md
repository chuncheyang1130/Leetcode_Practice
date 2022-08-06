### Implementation
- Calculate the sum of the block from left-top corner (0, 0) to the right-bottom corner (i, j) in advance, i < mat.size(), j < mat[0].size()
- For the query block, supposed that left-top corner is (d, l) and right-bottom corner is (u, r), calculate sum[u][r]  - sum[d-1][r] - sum[u][l-1] + sum[d-1][l-1]
​
### Complexity
- O(n * m) in time
- O(n * m) in space
​
​