# Median of Two Sorted Arrays

This repository contains a solution for LeetCode Problem 4: Median of Two Sorted Arrays.

## Problem Description

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return the median of the two sorted arrays.

### Example 1:
```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```

### Example 2:
```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

## Solution Approach

The solution uses a binary search approach to achieve O(log(m+n)) time complexity:

1. Binary search is performed on the smaller array to find the correct partition
2. The partition ensures that the left half contains half of the total elements
3. The solution checks if the partition is correct by comparing boundary elements
4. The median is calculated based on whether the total length is odd or even

### Time Complexity
- O(log(min(m,n))) where m and n are the lengths of the input arrays

### Space Complexity
- O(1) as no extra space is used

## Usage

To compile and run the solution:

```bash
g++ median_of_two_sorted_arrays.cpp -o median
./median
```

The program includes test cases that demonstrate the solution with the example inputs.

## Implementation Details

The solution is implemented in C++ and includes:
- A `Solution` class with the `findMedianSortedArrays` method
- Detailed comments explaining the approach
- Test cases in the main function
- Edge case handling for empty arrays and single-element arrays

## Contributing

Feel free to submit issues and enhancement requests! 