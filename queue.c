#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void initialize(queue *q) { 
    q->front = NULL; 
    q->rear = NULL;
    q->s1 = NULL;
    q->s2 = NULL;
    q->size = 0;
}

bool empty(const queue *q) {
    return q->size == 0;
}

bool full(const queue *q) {
    return false;
}

void enqueue(queue *q, int x) {
    node* newNode = (node*)malloc(sizeof(node));
    
    if (newNode == NULL) {
        printf("Queue is full (memory allocation failed).\n");
        
    } 

    newNode->data = x;
    newNode->next = NULL;

    if (empty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }

    q->rear = newNode;
    q->size++;
    printf("Enqueued: %d\n", x);
}

int dequeue(queue *q) {
    if (empty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    node* temp = q->front;
    int x = temp->data;

    q->front = q->front->next;
    q->size--;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    printf("Dequeued: %d\n", x);

    return x;
}

// Opgave 4

// Funktion til at push et element ovenpå stack
void push(int element, node **head) {

    node *newNode = (node *)malloc(sizeof(node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = element;
    newNode->next = *head; // Peg på current head
    *head = newNode;       // Update head til new node
}

// Funktion til at pop et element fra stack
int pop(node **head) {
    if (*head == NULL) {
        printf("Stack is empty.\n");
        return -1; 
    }
    node *temp = *head;
    int poppedValue = temp->data; // Opbevar data ved return
    *head = (*head)->next; // Flyt head til next node
    free(temp); // Frigør old head node
    return poppedValue; // Returner popped value
}

// Funktion til enqueue et element ind i queue
void enqueueStack(queue *q, int x) {
    push(x, &q->s1); // Push element ovenpå first stack
}

// Funktion til dequeue et element fra queue
int dequeueStack(queue *q) {
    if (q->s2 == NULL) { // Hvis second stack er empty
        while (q->s1 != NULL) {
            push(pop(&q->s1), &q->s2); // Flyt elements fra s1 til s2
        }
    }
    return pop(&q->s2); // Pop top element fra second stack
}

