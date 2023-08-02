// Function to find the length of the longest substring without repeating characters
int lengthOfLongestSubstring(char *s) {
    int size = strlen(s); // Get the length of the input string
    int maxLength = 0; // Variable to store the maximum length of the substring without repeating characters

    for (int i = 0; i < size; i++) {
        char arr[size]; // Array to store the characters of the current substring
        int index = 0; // Variable to keep track of the current index in 'arr'

        // Loop through the string starting from the i-th position to find the longest substring
        for (int j = i; j < size; j++) {
            bool exist = false; // Variable to check if the current character already exists in 'arr'

            // Check if the current character 's[j]' exists in 'arr'
            for (int c = 0; c < index; c++) {
                if (arr[c] == s[j])
                    exist = true; // If found, mark 'exist' as true
            }

            // If the character already exists, break out of the loop to start a new substring
            if (exist)
                break;

            // Otherwise, add the character 's[j]' to 'arr' and increment the 'index'
            arr[index++] = s[j];
        }

        // After the inner loop finishes, 'index' holds the length of the current substring
        // If the current substring is longer than the current maximum length, update 'maxLength'
        if (index > maxLength)
            maxLength = index;
    }

    return maxLength; // Return the maximum length of the substring without repeating characters
}