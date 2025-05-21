#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include "stack_implementation.h"

//function to create a new stack instance
struct stack_t *newStack(void) {
    struct stack_t *stack = malloc(sizeof *stack);
    if (stack) {
        stack->head = NULL;
        stack->stackSize = 0;
    }
    return stack;
}

//function to return  the copy of the string
char *copyString(char *str) {
    char *tmp = malloc(strlen(str) + 1);
    if (tmp)
        strcpy(tmp, str);
    return tmp;
}

//function to add an element to the stack
void push(struct stack_t *theStack, char *value) {
    if (!theStack || !value) return;

    struct stack_entry *entry = malloc(sizeof *entry);
    if (entry) {
        entry->data = copyString(value);
        entry->next = theStack->head;
        theStack->head = entry;
        theStack->stackSize++;
    } else {
        printf("Stack allocation failed\n");
    }
}

//function to return the top element of the stack
char *top(struct stack_t *theStack) {
    if (theStack && theStack->head)
        return theStack->head->data;
    else
        return NULL;
}

//function to return the stack pointer
void *stackpointer(struct stack_t *theStack) {
    if (theStack)
        return theStack->head;
    else
        return NULL;
}

//function to remove the top element of the stack
char *pop(struct stack_t *theStack) {
    if (!theStack || theStack->head == NULL)
        return NULL;

    struct stack_entry *tmp = theStack->head;
    char *data = copyString(tmp->data);

    theStack->head = tmp->next;
    theStack->stackSize--;

    free(tmp->data);
    free(tmp);

    return data;
}
