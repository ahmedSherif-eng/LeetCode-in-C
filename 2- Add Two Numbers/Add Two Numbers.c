// Function to create a new ListNode with the given data value
struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode) {
        newNode->val = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to add two numbers represented as linked lists
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int result, reminder = 0; // Variables to store the result and reminder from addition
    struct ListNode* ret = NULL; // The head of the resulting linked list
    struct ListNode* node; // Pointer to traverse the resulting linked list

    while (l1 || l2) {
        if (l1 && l2) {
            // If both linked lists have nodes at the current position, add the values and the reminder
            result = ((l1->val + l2->val) % 10) + reminder;
            reminder = (l1->val + l2->val) / 10;
            if (result >= 10) {
                reminder = result / 10;
                result %= 10;
            }

            l1 = l1->next;
            l2 = l2->next;
        } else if (l1 && !l2) {
            // If l2 has no more nodes, but l1 has, then add l1 value with the reminder
            result = (l1->val) + reminder;
            if (result >= 10) {
                reminder = result / 10;
                result %= 10;
            } else {
                reminder = 0;
            }
            l1 = l1->next;
        } else {
            // If l1 has no more nodes, but l2 has, then add l2 value with the reminder
            result = (l2->val) + reminder;
            if (result >= 10) {
                reminder = result / 10;
                result %= 10;
            } else {
                reminder = 0;
            }
            l2 = l2->next;
        }

        if (!ret) {
            // If the resulting list is empty, create the head node and set the 'node' pointer
            ret = createNode(result);
            node = ret;
        } else {
            // If the resulting list already has nodes, create a new node and link it to the 'node' pointer
            node->next = createNode(result);
            node = node->next;
        }
    }

    // If there is a non-zero reminder left after the addition, create a new node to hold it
    if (reminder != 0) {
        node->next = createNode(reminder);
        node = node->next;
    }

    return ret; // Return the head of the resulting linked list
}