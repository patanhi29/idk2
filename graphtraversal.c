#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return -1;
    }
    int data = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void bfs(struct Graph* graph, int startVertex) {
    struct Queue* queue = createQueue();
    graph->visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (queue->front != NULL) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->data;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");

    // Reset visited array for future traversals
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
}

void dfsUtil(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->data;
        if (graph->visited[connectedVertex] == 0) {
            dfsUtil(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

void dfs(struct Graph* graph, int startVertex) {
    dfsUtil(graph, startVertex);
    printf("\n");

    // Reset visited array for future traversals
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
}

int main() {
    struct Graph* graph = NULL;
    int choice, vertices, edges, i, src, dest, startVertex;

    printf("\nMenu:\n1. Create Graph\n2. Add Edge\n3. BFS Traversal\n4. DFS Traversal\n5. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of vertices: ");
                scanf("%d", &vertices);
                graph = createGraph(vertices);
                printf("Graph created with %d vertices.\n", vertices);
                break;
            case 2:
                if (graph == NULL) {
                    printf("Create a graph first.\n");
                } else {
                    printf("Enter edge (src dest): ");
                    scanf("%d %d", &src, &dest);
                    addEdge(graph, src, dest);
                    printf("Edge added between %d and %d.\n", src, dest);
                }
                break;
            case 3:
                if (graph == NULL) {
                    printf("Create a graph first.\n");
                } else {
                    printf("Enter the starting vertex for BFS: ");
                    scanf("%d", &startVertex);
                    printf("BFS Traversal: ");
                    bfs(graph, startVertex);
                }
                break;
            case 4:
                if (graph == NULL) {
                    printf("Create a graph first.\n");
                } else {
                    printf("Enter the starting vertex for DFS: ");
                    scanf("%d", &startVertex);
                    printf("DFS Traversal: ");
                    dfs(graph, startVertex);
                }
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
