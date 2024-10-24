#pragma once

#include <stdbool.h>

#include "node.h"
 
typedef struct queue {
  int size;
  node *front;
  node *rear;
  node *s1; //Første stack
  node *s2; //Anden stack
} queue;

//opgave 3
void initialize(queue *q);
bool empty(const queue *q);
bool full(const queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);

//opgave 4
void push(int element, node **head);
int pop(node **head);
void enqueueStack(queue *q, int x);
int dequeueStack(queue *q);

