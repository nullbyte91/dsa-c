#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node*
getNewNode(int data){
    struct Node* node = malloc(sizeof(struct Node));
    assert(node);
    
    node->data = data;
    node->next = NULL;
    return node;
}

void
insert(struct Node** rootPtr, int data){
    struct Node* node = getNewNode(data);

    if (*(rootPtr) == NULL){
        *(rootPtr) = node;
    } else {
        node->next = *(rootPtr);
        *(rootPtr) = node;
    }    
}

void
traversal(struct Node* rootPtr){
    if (rootPtr == NULL){
        printf("Linked list is empty\n");
        return;
    } else {
        while(rootPtr != NULL){
            printf("%d ", rootPtr->data);
            rootPtr = rootPtr->next;
        }
    }
}

void
delete(struct Node** rootPtr){
    if (*(rootPtr) == NULL){
        printf("Linked list is empty\n");
        return;
    } else {
        struct Node* deleteNode = *(rootPtr);
        printf("Delete: %d ", deleteNode->data);
        *(rootPtr) = deleteNode->next;
        free(deleteNode);
    }
}

int 
main(int argc, char** argcv){
    struct Node *rootPtr = NULL;
    
    for(int i=0; i<5; i++){
        insert(&rootPtr, i);
    }
    traversal(rootPtr);

    for(int i=0; i<5; i++){
        delete(&rootPtr);
    }

    free(rootPtr);
    
    return 0;
}