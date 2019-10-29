#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


struct Elt{
    int data;
    struct elt* next;
};

struct Queue{
    struct Elt* front;  //deQueue from here
    struct Elt* rear;   //enQueue from here
};

/* Create a initial queue */
struct Queue*
createQueue(){
    struct Queue* q = malloc(sizeof(struct Queue));
    assert(q);
    q->front = NULL;
    q->rear = NULL;
    return q;
}

/* Create a new queue node using Elt structure */
struct Elt*
getNewNode(int data){
    struct Elt* node = malloc(sizeof(struct Elt));
    assert(node);
    node->data = data;
    node->next = NULL;
    return node;
}

/* enQueue */
void 
enQueue(struct Queue** q, int data){
    struct Elt* node = getNewNode(data);
    struct Queue* e = *q;
    if (e->front == NULL){
        e->front = node;
    } else {
        e->rear->next = node;
    }
    e->rear = node;
}

/* traversal */
void
traversal(struct Queue* q){
    struct Elt* e;
    for (e=q->front; e!=0; e=e->next){
        printf("%d ", e->data);
    }
}

/* deQueue */
void
deQueue(struct Queue* q){
    struct Elt* e = q->front;
    if (q->front == NULL && q->rear == NULL){
        printf("Queue is empty\n");
        return;
    } else {
        printf("%d ", e->data);
        q->front = e->next;
    }
    free(e);
}

/* Main Function */
int
main(int argc, char** argcv){
    struct Queue* q = createQueue();

    for (int i=0; i<5; i++){
        enQueue(&q, i);        
    } 

    traversal(q);
    
    for (int i=0; i<5; i++){
        deQueue(q);        
    }
    
    return 0;
}