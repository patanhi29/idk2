// Time Complexity:
// initStack: O(1)
// push: O(1)
// pop: O(1)
// peek: O(1)
// display: O(n)
// Space Complexity:
// Overall: O(MAX)
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent a stack
struct Stack {
    int top;
    int items[MAX];
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element to the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow! Unable to push %d\n", item);
        return;
    }
    stack->items[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Unable to pop\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// Function to display the elements of the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->items[i]);
    }
}

// Function to peek the topmost element of the stack
void peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Topmost element is: %d\n", stack->items[stack->top]);
}

int main() {
    struct Stack stack;
    initStack(&stack);

    int choice, item;

    printf("\nMenu:\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &item);
                push(&stack, item);
                break;
            case 2:
                item = pop(&stack);
                if (item != -1) {
                    printf("Popped element: %d\n", item);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                peek(&stack);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
