bool isPalindrome(int x) {
    // Check if the number is negative, which can't be a palindrome
    if (x < 0)
        return false;

    int original = x; // Store the original number for later comparison
    int reversed = 0; // Initialize the variable to store the reversed number

    while (x) {
        // Check if multiplying 'reversed' by 10 will exceed the maximum integer value
        if ((long long)(reversed * 10LL) < INT_MAX) {
            reversed = (reversed * 10) + x % 10; // Append the last digit of 'x' to 'reversed'
            x /= 10; // Remove the last digit from 'x'
        } else {
            // If 'reversed' would exceed INT_MAX, exit the loop to prevent overflow
            break;
        }
    }

    // Check if the reversed number is equal to the original number
    return (reversed == original);
}