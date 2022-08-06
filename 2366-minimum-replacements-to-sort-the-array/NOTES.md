### Implementation
- Start from the second element counting from back of the list, if the number is bigger than the number after it, then calculate how many number can the current number be separated into
- When separating the number, we want the number be seperated into is as average as possible, so that maximize the numbers to be seperated afterwards
- Calculate ceil(nums[i] / nums[i+1]) to know how many number it should be seperated into to avoid the average > nums[i+1]
- If 1 number is separated into n numbers, then add (n-1) to total
​
### Complexity
- O(n) in times
- O(1) in extra space
​
​