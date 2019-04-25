#ifndef stack_h
#define stack_h

struct Stack;
struct Stack *createStack(int max);
void push(struct Stack *s, int item);
int pop(struct Stack *s);
int duplicate(struct Stack *s, int item);

#endif /* stack_h */
