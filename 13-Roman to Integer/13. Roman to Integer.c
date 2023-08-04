// Function to convert a Roman numeral string 's' to an integer
int romanToInt(char *s) {
    int size = strlen(s); // Get the length of the input Roman numeral string
    int numbers[size]; // Array to store integer values corresponding to each Roman numeral character
    int result = 0; // Variable to store the final result (integer equivalent of the Roman numeral)

    // Loop through the Roman numeral string and map each character to its corresponding integer value
    for (int i = 0; i < size; i++) {
        switch (s[i]) {
            case 'I':
                numbers[i] = 1;
                break;
            case 'V':
                numbers[i] = 5;
                break;
            case 'X':
                numbers[i] = 10;
                break;
            case 'L':
                numbers[i] = 50;
                break;
            case 'C':
                numbers[i] = 100;
                break;
            case 'D':
                numbers[i] = 500;
                break;
            case 'M':
                numbers[i] = 1000;
                break;
        }
    }

    // Special case for a Roman numeral string of size 1, return the corresponding integer directly
    if (size == 1) {
        result = numbers[0];
        return result;
    }

    // Loop through the array of integer values and calculate the final result
    for (int i = 0; i < size - 1; i++) {
        if (numbers[i] < numbers[i + 1]) {
            // If the current number is smaller than the next one, it represents a subtractive pair
            // Calculate the subtraction and skip the next number in the loop
            result = result + numbers[i + 1] - numbers[i];
            i++;
        } else {
            // If the current number is greater than or equal to the next one, add it to the result
            result += numbers[i];
        }
    }

    // Check if the last number is not involved in any subtractive pair and add it to the result
    if (size >= 2 && numbers[size - 2] >= numbers[size - 1])
        result += numbers[size - 1];

    return result; // Return the final integer equivalent of the Roman numeral
}