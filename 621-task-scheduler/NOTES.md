### Implementation
- Use priority queue as container, every time pop the task with most remaining, and subtract it by 1
- When finish arranging a round of task, push those tasks used in the last round back if there are remaining of certain task
- For those rounds with full tasks, add n+1 to the total count if it is not last round, and add how many tasks is arranged in the last round
​
### Complexity
- O(n * len(tasks)) in time
- O(1) in extra space
​
​