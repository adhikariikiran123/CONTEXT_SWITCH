#include <stdio.h>
#include <stdlib.h>
#include "queue_implementation.h"

int arr[4];

//function to create a queue
Queue *createQueue(int maxElements) {
    Queue *Q;
    Q = (Queue *)malloc(sizeof(Queue));
    Q->elements = (int *)malloc(sizeof(int) * maxElements);
    Q->size = maxElements;
    Q->s = 0;
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

//function to enqueue an element into the queue, if the queue is full it will not add any element
void Enqueue(Queue *Q, int element) {
    if ((Q->front == 0 && Q->rear == Q->size - 1) || 
        (Q->rear == (Q->front - 1) % (Q->size - 1))) {
        printf("Queue is Full");
        return;
    }

    if (Q->front == -1) {
        Q->front = 0;
        Q->rear = 0;
        Q->elements[Q->rear] = element;
        Q->s++;
    } else if (Q->rear == Q->size - 1 && Q->front != 0) {
        Q->rear = 0;
        Q->elements[Q->rear] = element;
        Q->s++;
    } else {
        Q->rear++;
        Q->elements[Q->rear] = element;
        Q->s++;
    }
    return;
}

//function to dequeue an element from the queue, if the queue is empty it will not remove any element
int Dequeue(Queue *Q) {
    if (Q->front == -1) {
        return -1;
    }

    int data = Q->elements[Q->front];
    Q->elements[Q->front] = -1;

    if (Q->front == Q->rear) {
        Q->front = -1;
        Q->rear = -1;
        Q->s--;
    } else if (Q->front == Q->size - 1) {
        Q->front = 0;
        Q->s--;
    } else {
        Q->front++;
        Q->s--;
    }
    return data;
}

//function to get the first element of the queue
int front(Queue *Q) {
    if (Q->front == -1) {
        return -1;
    }
    return Q->elements[Q->front];
}

//function to display the elements of the queue
int display(Queue *Q) {
    int arr[4];
    int r = 0;

    if (Q->front == -1) {
        printf("Queue is Empty\n");
    } else {
        if (Q->rear >= Q->front) {
            printf("Queue is:\n");
            for (int y = Q->front; y <= Q->rear; y++) {
                printf("%d ", Q->elements[y]);
                arr[r] = Q->elements[y];
            }
        } else {
            printf("Queue is:\n");
            for (int y = Q->front; y < Q->size; y++) {
                printf("%d ", Q->elements[y]);
                arr[r] = Q->elements[y];
                r++;
            }
            for (int y = 0; y <= Q->rear; y++) {
                printf("%d ", Q->elements[y]);
                arr[r] = Q->elements[y];
                r++;
            }
        }

        for (int y = 0; y < 4; y++) {
            if (arr[y] == 0 || arr[y] == 1 || arr[y] == 2 || arr[y] == 3) {
            } else {
                arr[y] = -1;
            }
        }
        printf("\n");
    }
}

//function to search for an element in the queue
int search(Queue *Q, int element) {
    if (Q->size == 0) {
        printf("Queue is Empty\n");
    } else {
        int j;
        for (j = Q->front; j <= Q->rear; j++) {
            if (Q->elements[j] == element)
                return 1;
        }
    }
}
