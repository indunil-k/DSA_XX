/**
 * LeetCode Problem 4: Median of Two Sorted Arrays
 * 
 * Problem Description:
 * Given two sorted arrays nums1 and nums2 of size m and n respectively,
 * return the median of the two sorted arrays.
 * 
 * Time Complexity: O(log(m+n))
 * Space Complexity: O(1)
 * 
 * Approach:
 * 1. Use binary search on the smaller array to find the correct partition
 * 2. Ensure the left half contains half of the total elements
 * 3. Check if the partition is correct by comparing maxLeft1 <= minRight2 and maxLeft2 <= minRight1
 * 4. Return median based on total length (odd/even)
 */

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array for optimization
        if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
            // Binary search partition points
            int partition1 = (low + high) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            // Get the four boundary numbers
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            // Check if we found the correct partition
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If total length is odd, return max of left half
                if ((m + n) % 2 == 0) 
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                else 
                    return max(maxLeft1, maxLeft2);
            }
            // Adjust binary search boundaries
            else if (maxLeft1 > minRight2) {
                high = partition1 - 1;  // Move left
            } else {
                low = partition1 + 1;   // Move right
            }
        }

        return 0.0; // This case should never be reached
    }
};

// Example usage
int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Test Case 1: " << solution.findMedianSortedArrays(nums1, nums2) << endl;  // Expected: 2.0
    
    // Test Case 2
    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << "Test Case 2: " << solution.findMedianSortedArrays(nums1, nums2) << endl;  // Expected: 2.5
    
    return 0;
} 