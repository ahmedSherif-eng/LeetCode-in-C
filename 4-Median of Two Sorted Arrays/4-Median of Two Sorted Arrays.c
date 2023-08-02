// Function to find the median of two sorted arrays
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double result; // Variable to store the result (median)
    int finalArray[nums1Size + nums2Size]; // Array to store the merged sorted array
    int ptr1 = 0, ptr2 = 0; // Pointers to track the current position in nums1 and nums2 arrays
    int i; // Loop counter variable

    // Merge the two sorted arrays into the finalArray in ascending order
    for (i = 0; i < nums1Size + nums2Size; i++) {
        if (ptr1 >= nums1Size) {
            finalArray[i] = nums2[ptr2++]; // If nums1 has no elements left, add the remaining elements from nums2
        } else if (ptr2 >= nums2Size) {
            finalArray[i] = nums1[ptr1++]; // If nums2 has no elements left, add the remaining elements from nums1
        } else if (nums1[ptr1] < nums2[ptr2]) {
            finalArray[i] = nums1[ptr1++]; // If the current element in nums1 is smaller, add it to finalArray
        } else {
            finalArray[i] = nums2[ptr2++]; // If the current element in nums2 is smaller or equal, add it to finalArray
        }
    }
    
    // Calculate the median based on the size of the merged array (nums1Size + nums2Size)
    if ((nums1Size + nums2Size) % 2 == 0) {
        // If the merged array has even elements, the median is the average of the middle two elements
        result = (finalArray[(nums1Size + nums2Size) / 2] + finalArray[(nums1Size + nums2Size) / 2 - 1]) / 2.0;
    } else {
        // If the merged array has odd elements, the median is the middle element
        result = finalArray[(nums1Size + nums2Size) / 2];
    }
    
    return result; // Return the calculated median
}