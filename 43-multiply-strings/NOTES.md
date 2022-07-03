### Implementation
- First need to know the max digit number of the result, create a vector of this length with all 0
- Just like we do multiplication, start from the right most digit of multiplier and times the multiplicand digit by digit, also record carry
- Record the carry of each digit multiplication (result divided by 10), also mod the result (mod 10) and add to the position it should be of the vector
​
### Complexity
- O(n * m) in time
- O(n+m) in space
​
​