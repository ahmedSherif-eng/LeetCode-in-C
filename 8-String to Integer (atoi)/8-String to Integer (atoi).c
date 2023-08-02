int myAtoi(char *s) {
	int size = strlen(s), i = 0;
	long long number = 0;
	bool negative = false;
	char signCounter = 0; // Variable to keep track of sign characters encountered

	// Skip leading whitespaces
	while (i < size && s[i] == ' ')
	i++;

	// Check for sign characters ('+' or '-')
	while (i < size && (s[i] == '+' || s[i] == '-')) {
		if (s[i] == '+') {
			if (signCounter > 0)
			return 0; // If multiple '+' characters are encountered, return 0
			signCounter++;
		} else {
			if (signCounter > 0)
			return 0; // If multiple '-' characters are encountered, return 0
			signCounter++;
			negative = true; // Set the 'negative' flag for negative numbers
		}
		i++;
	}

	// Skip leading zeros
	while (i < size && s[i] == '0')
	i++;

	// Convert the remaining digits to an integer
	for (i; i < size; i++) {
		if (s[i] <= '9' && s[i] >= '0')
		number = number * 10LL + s[i] - '0'; // Use 10LL for long long operations
		else
		break; // Stop conversion if any non-numeric character is encountered

		// Check if the number exceeds the maximum allowed integer value
		if (number > INT_MAX) {
			return (negative ? INT_MIN : INT_MAX);
		}
	}

	// Apply the appropriate sign to the number and return the integer value
	return (negative ? -number : number);
}