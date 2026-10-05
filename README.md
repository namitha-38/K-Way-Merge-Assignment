# K-Way Merge Assignment

## Aim
Implement and compare K-way merging using a Min Heap and pairwise merging.

## Input
L1 = 10, 30, 50, 70
L2 = 20, 40, 60, 80
L3 = 15, 35, 55, 75

## Programs
- `source_code/kway_heap.c` - K-way merge using Min Heap
- `source_code/pairwise_merge.c` - Pairwise merging

## Output
Both approaches produce:
`10 15 20 30 35 40 50 55 60 70 75 80`

## Complexity
- Min Heap: O(N log K) time, O(K) auxiliary space
- Pairwise: O(NK) time in the general sequential approach, O(N) intermediate space

## Repository Contents
- Source code
- Input data
- Output
- Trace table
- Complexity analysis
- Comparison table
- Final conclusion

## Conclusion
For a small number of lists, pairwise merging is straightforward. For a larger
number of sorted files, the Min Heap approach is more scalable.
