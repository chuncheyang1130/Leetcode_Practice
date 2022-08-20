### Implementation
- Record how much gas remain, run a for loop to visit each gas station
- Use a priority queue to record how much gas can get in the previous stations and sort in decending order -> always start fueling with the maximum amount so far
- When visit gas station, first check if the car is able to reach the position, that is, can the car reach the station even if the car get fueled at all gas stations in front
- If the car can reach the station, then push the amount of gas that can get fueled from the station into a priority queue, else return -1
- Update the current position and check if the car can reach target
​
### Complexity
- O(nlogn) in time
- O(n) in extra space
​
​
​