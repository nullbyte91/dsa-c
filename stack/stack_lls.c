#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY_STACK 0

struct Stack{
    int val;
    struct Stack *next;
};

void 
push(struct Stack **s, int val){
    struct Stack* stack_node = malloc(sizeof(struct Stack));
    stack_node->val = val;
    stack_node->next = *s;
    *s = stack_node;
}

void
printStack(const struct Stack* s){
    while (s != NULL){
        printf("%d ", s->val);
        s = s->next;
    }
    putchar('\n');
}

void 
pop(struct Stack** s){
    struct Stack* e = *s;
    printf("Pop: %d \n", e->val);
    *s = e->next;
    free(e);
}

int
peek(const struct Stack* s){
    return s->val;
}

bool
isEmpty(const struct Stack* s){
    return s == NULL;
}

int
main(int argc,char** argcv){
    struct Stack* s = EMPTY_STACK;

    for (int i=0; i<5; i++){
        push(&s, i);
    }
    printStack(s);
    printf("Peek: %d\n", peek(s));
    for (int i=0; i<5; i++){
        pop(&s);
    }

}