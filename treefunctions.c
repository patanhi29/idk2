#include <stdio.h>
#include <stdlib.h>

// Structure for a node of the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Structure for stack node
struct StackNode {
    struct Node* data;
    struct StackNode* next;
};

// Structure for stack
struct Stack {
    struct StackNode* top;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a new stack node
struct StackNode* createStackNode(struct Node* data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

// Function to push a node onto the stack
void push(struct Stack* stack, struct Node* data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to pop a node from the stack
struct Node* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    struct StackNode* temp = stack->top;
    stack->top = stack->top->next;
    struct Node* popped = temp->data;
    free(temp);
    return popped;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to count nodes in the BST
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to calculate height of the BST using stack
int heightUsingStack(struct Node* root) {
    if (root == NULL)
        return -1;

    int maxHeight = 0;
    int currentHeight = 0;
    struct Stack* stack = createStack();
    struct Node* current = root;
    struct Node* lastVisited = NULL;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
            currentHeight++;
            if (currentHeight > maxHeight)
                maxHeight = currentHeight;
        }
        current = stack->top->data;
        if (current->right != NULL && current->right != lastVisited) {
            current = current->right;
        } else {
            lastVisited = pop(stack);
            currentHeight--;
            current = NULL;
        }
    }
    return maxHeight;
}

// Function to perform in-order traversal of the BST using a stack
void inorderUsingStack(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* stack = createStack();
    struct Node* current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }
        current = pop(stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

// Function to perform mirror image of the BST
struct Node* mirrorImage(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    struct Node* mirror = createNode(root->data);
    mirror->left = mirrorImage(root->right);
    mirror->right = mirrorImage(root->left);

    return mirror;
}

// Function to print elements of the BST
void printElements(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    printElements(root->left);
    printElements(root->right);
}

// Main function to demonstrate the BST operations
int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        printf("\n\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Count nodes\n");
        printf("3. Height of Tree\n");
        printf("4. In-order traversal\n");
        printf("5. Mirror Image\n");
        printf("6. Print elements\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Number of nodes in the tree: %d\n", countNodes(root));
                break;
            case 3:
                printf("Height of the tree: %d\n", heightUsingStack(root));
                break;
            case 4:
                printf("In-order traversal: ");
                inorderUsingStack(root);
                printf("\n");
                break;
            case 5:
                printf("Mirror Image created.\n");
                root = mirrorImage(root);
                break;
            case 6:
                printf("Elements of the tree: ");
                printElements(root);
                printf("\n");
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}
