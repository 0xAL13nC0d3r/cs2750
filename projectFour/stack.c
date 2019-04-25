#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


struct Stack{
    int top;
    int max;
    int *array;
};

struct Stack *createStack(int max) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->array = (int*) malloc(stack->max * sizeof(int));
    return stack;
}


void push(struct Stack *s, int item) {
    s->array[++s->top] = item;
}

int pop(struct Stack *s) {
    if(s->top == -1) {
        printf("Stack is Empty!");
        return 1000;
    } else {
        return s->array[s->top--];
    }
}

void peek(struct Stack *s) {
    printf("%d is on top of the stack\n", s->array[s->top]);
    return;
}

int duplicate(struct Stack *s, int item) {
    for(int i = s->top; i >= 0; i--) {
        if(s->array[i] == item) {
            return 1;
        }
    }
    return 0;
}
