#define STACK_SIZE 1024

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

struct StackEntry {
  int line;
  int pos;
  char $char;
};

struct Stack {
  struct StackEntry entries[STACK_SIZE];
  int top;
};

/* Returns the size of the stack */
int stack_size(struct Stack *stack) {
  return stack->top == 0 ? TRUE : FALSE;
}

/* Check if the stack is empty */
int stack_is_empty(struct Stack *stack) {
  return stack->top == 0 ? TRUE : FALSE;
}

/* Check if the stack is full */
int stack_is_full(struct Stack *stack) {
  return stack->top == STACK_SIZE ? TRUE : FALSE;
}

/* Return the topmost element in the stack */
struct StackEntry *stack_peek(struct Stack *stack) {
  return &stack->entries[stack->top - 1];
}

/* Push an entry on the top  of the stack */
int stack_push(struct Stack *stack, struct StackEntry *entry) {
  if (!stack_is_full(stack)) {
    stack->entries[stack->top] = *entry;
    stack->top++;
    return TRUE;
  }

  return FALSE;
}

/* Pop the top entry from the stack */
struct StackEntry *stack_pop(struct Stack *stack) {
  if (!stack_is_empty(stack)) {
    stack->top--;
    return &stack->entries[stack->top];
  }

  return NULL;
}