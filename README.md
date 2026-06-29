# weighted-interval-scheduling
Implementation of the classic Weighted Interval Scheduling algorithm using Dynamic Programming and Binary Search.

## Features

- Sorts jobs by finish time
- Binary search to locate the latest compatible interval
- Dynamic programming optimization
- Reconstruction of the optimal job schedule
- Displays maximum profit and selected jobs

## Technologies

- C++
- STL
- Dynamic Programming
- Binary Search

## Algorithm

| Operation | Complexity |
|-----------|------------|
| Sorting | O(n log n) |
| Binary Search | O(log n) |
| Dynamic Programming | O(n) |
| Overall | O(n log n) |

## Example Output

```text
Jobs Selected

Start  Finish  Profit
2      5       6
5      8       11

Maximum Profit: 17
```

## What I Learned

- Dynamic programming optimization
- Binary search for predecessor lookup
- Solution reconstruction using backtracking
- Time complexity optimization
- Interval scheduling techniques
