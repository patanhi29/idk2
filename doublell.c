

// ------doubly Linked List Code-----------------
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

node* a, * temp, * head;

void makeList() {
    int n;
    head = (node*)malloc(sizeof(node));
    printf("\nEnter number of nodes:");
    scanf("\n%d", &n);
    printf("Enter data:");
    scanf("%d", &head->data);
    head->prev = NULL;
    head->next = NULL;
    a = head;
    for (int i = 1; i < n; i++) {
        temp = (node*)malloc(sizeof(node));
        printf("\nEnter data:");
        scanf("\n%d", &temp->data);
        temp->next = NULL;
        temp->prev = a;
        a->next = temp;
        a = a->next;
    }
}

void inAtStart() {
    printf("\nEnter data: ");
    temp = (node*)malloc(sizeof(node));
    scanf("\n%d", &temp->data);
    temp->next = head;
    head->prev = temp;
    temp->prev = NULL;
    head = temp;
}

void inAtLocation() {
    printf("\nEnter position:");
    int l;
    scanf("\n%d", &l);
    temp = (node*)malloc(sizeof(node));
    a = head;
    for (int i = 1; i < l; i++) {
        a = a->next;
    }
    printf("\nEnter data:");
    scanf("\n%d", &temp->data);
    temp->next = a->next;
    a->next = temp;
    temp->prev = a;
}

void inAtEnd() {
    printf("\nEnter data:");
    temp = (node*)malloc(sizeof(node));
    scanf("\n%d", &temp->data);
    a = head;
    while (a->next != NULL) {
        a = a->next;
    }
    a->next = temp;
    temp->prev = a;
    temp->next = NULL;
}

void delAtStart() {
    if (head != NULL) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    }
}

void delAtEnd() {
    if (head != NULL) {
        a = head;
        while (a->next != NULL) {
            temp = a;
            a = a->next;
        }
        if (temp != NULL) {
            temp->next = NULL;
        }
    }
}

void print() {
    a = head;
    printf("\nList:");
    while (a != NULL) {
        printf(" %d ", a->data);
        a = a->next;
    }
}

int main() {
    int choice, ans = 1;
    do {
        printf("\nMenu:");
        printf("\n1)Create list \n2)Insert at start\n3)Insert at a position\n4)Insert at end");
        printf("\n5)Delete starting node\n6)Delete end node\n7)Print list\n8)Exit(0)");
        printf("\nEnter choice:");
        scanf("\n%d", &choice);
        switch(choice){
        case 1:
            makeList();
            break;

        case 2:
            inAtStart();
            break;

        case 3:
            inAtLocation();
            break;

        case 4:
            inAtEnd();
            break;

        case 5:
            delAtStart();
            break;

        case 6:
            delAtEnd();
            break;

        case 7:
            print();
            break;

        case 8:
            ans = 0;
            printf("\nSucessfully executed");
            break;

        default:
            printf("Insert correct choice");
            break;
        }
    } while (ans == 1);

    return 0;
}
