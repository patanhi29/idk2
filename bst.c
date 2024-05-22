
#include<stdio.h>

#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

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

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void preorderRecursive(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

void inorderRecursive(struct Node* root) {
    if (root != NULL) {
        inorderRecursive(root->left);
        printf("%d ", root->data);
        inorderRecursive(root->right);
    }
}

void postorderRecursive(struct Node* root) {
    if (root != NULL) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        printf("%d ", root->data);
    }
}

void preorderWithoutRecursion(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top >= 0) {
        struct Node* node = stack[top--];
        printf("%d ", node->data);

        if (node->right) {
            stack[++top] = node->right;
        }
        if (node->left) {
            stack[++top] = node->left;
        }
    }
}

void inorderWithoutRecursion(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);

        current = current->right;
    }
}

void postorderWithoutRecursion(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        struct Node* node = stack1[top1--];
        stack2[++top2] = node;

        if (node->left) {
            stack1[++top1] = node->left;
        }
        if (node->right) {
            stack1[++top1] = node->right;
        }
    }

    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
}

void displayMenu() {
    printf("\n\nMenu:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Preorder Traversal (with recursion)\n");
    printf("4. Inorder Traversal (with recursion)\n");
    printf("5. Postorder Traversal (with recursion)\n");
    printf("6. Preorder Traversal (without recursion)\n");
    printf("7. Inorder Traversal (without recursion)\n");
    printf("8. Postorder Traversal (without recursion)\n");
    printf("9. Exit\n");
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Preorder traversal (with recursion): ");
                preorderRecursive(root);
                printf("\n");
                break;
            case 4:
                printf("Inorder traversal (with recursion): ");
                inorderRecursive(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder traversal (with recursion): ");
                postorderRecursive(root);
                printf("\n");
                break;
            case 6:
                printf("Preorder traversal (without recursion): ");
                preorderWithoutRecursion(root);
                printf("\n");
                break;
            case 7:
                printf("Inorder traversal (without recursion): ");
                inorderWithoutRecursion(root);
                printf("\n");
                break;
            case 8:
                printf("Postorder traversal (without recursion): ");
                postorderWithoutRecursion(root);
                printf("\n");
                break;
            case 9:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 9);

    return 0;
}


















