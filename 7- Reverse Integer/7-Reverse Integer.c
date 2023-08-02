// Function to reverse the digits of an integer
int reverse(int x) {
    int res = 0; // Variable to store the reversed integer
    bool negative = false; // Flag to indicate if the input integer is negative
    bool maxInt = false; // Flag to indicate if the reversed integer exceeds the maximum allowed integer value

    if (x < 0) {
        negative = true; // If the input integer is negative, set the 'negative' flag
        if (x == INT_MIN)
            return 0; // Check if the input integer is the minimum integer value (-2147483648), in which case, return 0 (overflow)
        x *= -1; // Convert the negative integer to positive for the reverse operation
    }

    while (x) {
        // Check if the next digit added to the result will exceed the maximum allowed integer value
        if (res * 10L + (x % 10) > INT_MAX) {
            maxInt = true; // Set the 'maxInt' flag if the maximum value is exceeded
            break;
        }
        res = res * 10 + (x % 10); // Reverse the integer by taking the last digit of 'x' and adding it to 'res'
        x /= 10; // Move to the next digit in 'x'
    }

    if (maxInt)
        res = 0; // If the maximum integer value is exceeded during the reverse process, set the result to 0 (overflow)
    else if (negative)
        res *= -1; // If the input integer was initially negative, convert the result back to negative

    return res; 
}