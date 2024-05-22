#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enqueue();
void dequeue();
void peek();
void display();
int main(){
    int choice ,element;
    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the element you want to insert: ");
                    scanf("%d",&element);
                    enqueue(element);
                    break;
            case 2: dequeue();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            case 5: printf("Exiting program.\n");
                    return 0; // Exiting the program
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

void enqueue(int x)
{
    if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else if(((rear+1)%N)==front){
        printf("Queue is full\n");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    else if(front==rear){
        printf("Deleted element is: %d\n",queue[front]);
        front=rear=-1;
    }
    else{
        printf("Deleted element is: %d\n",queue[front]);
        front=(front+1)%N;
    }
}

void display(){
    int i=front;
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("\nQueue is:\n");
        while(i!=rear)
        {
            printf("%d\n",queue[i]);
            i=(i+1)%N;
        }
        printf("%d\n",queue[rear]);
    }
}

void peek(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("Peek element is: %d\n",queue[front]);
    }
}
