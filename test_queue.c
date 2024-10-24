// test_queue.c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

int main() {
    queue q;
    initialize(&q);

    // Test (1): Efter initializing, queue skal være empty.
    assert(empty(&q) == true);
    printf("Test 1 passed: Queue er empty efter initialization.\n");

    // Test (2): Enqueue et element og så dequeue det.
    enqueue(&q, 17);
    int y = dequeue(&q);

    // Assert at queue er empty efter operationer og værdierne matcher
    assert(empty(&q) == true);
    assert(y == 17);
    printf("Test 2 passed: Queue opfører sig korrekt efter enqueueing og dequeueing.\n");

   // Test (3): Enqueue 2 elements og så dequeue dem.
    enqueue(&q, 10);  // x0
    enqueue(&q, 20);  // x1
    int y0 = dequeue(&q); // y0 skal være 10
    int y1 = dequeue(&q); // y1 skal være 20

    // Assert at queue er empty efter operations og værdierne matcher
    assert(empty(&q) == true);
    assert(y0 == 10); // Check om y0 lig med x0
    assert(y1 == 20); // Check om y1 lig med x1

    printf("Test 3 passed: Queue opfører sig korrekt efter enqueueing og dequeueing 2 elements.\n");

    
    enqueueStack(&q, 1); // Enqueue element 1
    enqueueStack(&q, 2); // Enqueue element 2
    enqueueStack(&q, 3); // Enqueue element 3

    printf("Dequeued: %d\n", dequeueStack(&q)); // Skal print 1
    printf("Dequeued: %d\n", dequeueStack(&q)); // Skal print 2

    enqueueStack(&q, 4); // Enqueue element 4

    printf("Dequeued: %d\n", dequeueStack(&q)); // Skal print 3
    printf("Dequeued: %d\n", dequeueStack(&q)); // Skal print 4

    return 0;
}
