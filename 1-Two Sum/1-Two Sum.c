#include <stdio.h>
#include <stdlib.h>

struct IntVector {
    int* data;
    size_t size;
};

struct IntVector twoSum(struct IntVector nums, int target) {
    struct IntVector ret;
    ret.data = (int*)malloc(2 * sizeof(int));
    ret.size = 2;
    
    for (size_t i = 0; i < nums.size - 1; i++) {
        for (size_t j = i + 1; j < nums.size; j++) {
            if (nums.data[i] + nums.data[j] == target) {
                ret.data[0] = (int)i;
                ret.data[1] = (int)j;
                return ret;
            }
        }
    }
    
    ret.data[0] = ret.data[1] = -1; // If no solution found, set the values to -1
    return ret;
}

int main() {
    // Example usage
    int arr[] = {2, 7, 11, 15};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    struct IntVector nums;
    nums.data = arr;
    nums.size = arr_size;

    int target = 9;

    struct IntVector result = twoSum(nums, target);

    printf("Indices of two numbers: %d, %d\n", result.data[0], result.data[1]);
    free(result.data); // Remember to free the allocated memory

    return 0;
}