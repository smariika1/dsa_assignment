# Q8: Write a program that generates a list of N random integers in the range [1, 1000], where N is provided by the user at run time. Then, perform the following tasks: (a) Ask the user to choose a sorting algorithm from the following: Bubble Sort, Selection Sort, Insertion Sort, Merge Sort (b) Sort the randomly generated numbers using the chosen algorithm. (c) Print the numbers before and after sorting. (d) Display the total number of comparisons and swaps (if applicable) performed by the chosen algorithm.

## Data Structure
- **Stats**: Tracks comparisons and swaps

## Sorting Algorithms Implemented

### 1. Bubble Sort
- Repeatedly swap adjacent elements if wrong order
- Time: O(n²), Space: O(1)

### 2. Selection Sort
- Find minimum and place at beginning
- Time: O(n²), Space: O(1)

### 3. Insertion Sort
- Insert each element into sorted portion
- Time: O(n²), Space: O(1)

### 4. Merge Sort
- Divide and conquer, merge sorted halves
- Time: O(n log n), Space: O(n)

## Main Function Flow
1. Get array size from user
2. Generate random numbers [1-1000]
3. Display sorting menu
4. Sort and track statistics
5. Display before/after and stats

## Sample Output
```
Enter number of elements: 10
Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Choice: 4

Before sorting: 234 567 123 890 456 789 345 678 901 432 
After sorting:  123 234 345 432 456 567 678 789 890 901 

Statistics:
Comparisons: 22
Swaps: 0
Time: 0.000032 seconds
```

## Complexity Comparison

| Algorithm | Best | Average | Worst | Space |
|-----------|------|---------|-------|-------|
| Bubble | O(n) | O(n²) | O(n²) | O(1) |
| Selection | O(n²) | O(n²) | O(n²) | O(1) |
| Insertion | O(n) | O(n²) | O(n²) | O(1) |
| Merge | O(n log n) | O(n log n) | O(n log n) | O(n) |
