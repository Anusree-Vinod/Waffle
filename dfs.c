// C program to implement DFS using a linked list
#include <stdio.h>
#include <stdlib.h>
int i;
// A structure to represent a node in the linked list
struct node {
    int data; // The data of the node
    struct node* next; // A pointer to the next node in the list
};

// A function to create a new node
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// A function to insert a node at the beginning of the linked list
void insert(struct node** head, int data) {
    struct node* temp = newNode(data);
    temp->next = *head;
    *head = temp;
}

// A function to print the linked list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// A function to perform DFS traversal from a given source vertex
void DFS(struct node** graph, int s, int V, int* visited) {
    // Mark the current node as visited and print it
    visited[s] = 1;
    printf("%d ", s);

    // Create a stack for DFS
    struct node* stack = NULL;

    // Push the current node to the stack
    insert(&stack, s);

    // Loop until the stack is empty
    while (stack) {
        // Pop a vertex from the stack
        int u = stack->data;
        stack = stack->next;

        // Get all the adjacent vertices of the popped vertex
        struct node* temp = graph[u];
        while (temp) {
            int v = temp->data;
            // If the adjacent vertex is not visited, push it to the stack and mark it as visited
            if (!visited[v]) {
                insert(&stack, v);
                visited[v] = 1;
                printf("%d ", v);
            }
            temp = temp->next;
        }
    }
}

// A function to test the program
int main() {
    // Create a graph of 5 vertices
    int V = 5;
    struct node** graph = (struct node**)malloc(V * sizeof(struct node*));
    for ( i = 0; i < V; i++) {
        graph[i] = NULL;
    }

    // Add edges to the graph
    insert(&graph[0], 1);
    insert(&graph[0], 2);
    insert(&graph[1], 2);
    insert(&graph[2], 0);
    insert(&graph[2], 3);
    insert(&graph[3], 3);

    // Print the graph
    for ( i = 0; i < V; i++) {
        printf("Adjacency list of vertex %d:\n", i);
        printList(graph[i]);
    }

    // Create an array to store the visited status of the vertices
    int* visited = (int*)malloc(V * sizeof(int));
    for ( i = 0; i < V; i++) {
        visited[i] = 0;
    }

    // Perform DFS from vertex 2
    printf("DFS traversal from vertex 2:\n");
    DFS(graph, 2, V, visited);

    // Free the graph and the visited array
    for ( i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);
    free(visited);

    return 0;
}

