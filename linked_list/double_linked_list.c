#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node*
getNewNode(int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    assert(newNode);
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
}

void
insert(struct Node** rootPtr, int data){
    struct Node* node = getNewNode(data);
    if (*(rootPtr) == NULL){
        *(rootPtr) = node;
    } else {
        struct Node* temp = *(rootPtr);
        node->next = temp;
        temp->prev = node;
        *(rootPtr) = node;  
    }
}

void
delete(struct Node** rootPtr){
    if (*(rootPtr) == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* deleteNode = *(rootPtr);
    printf("Del: %d ", deleteNode->data);
    struct Node* temp = *(rootPtr);
    temp = deleteNode->next;
    temp->prev = NULL;
    *(rootPtr) = temp;
    free(deleteNode);
}

void 
traversal(struct Node* rootPtr){
    if (rootPtr == NULL){
        printf("List is empty\n");
        return;
    } else {
        while (rootPtr != NULL){
            printf("%d ", rootPtr->data);
            rootPtr = rootPtr->next;
        }
        putchar('\n');
    }
}

int
main(int argc, char** argcv){
    struct Node* rootPtr = NULL;

    for (int i=0; i<5; i++){
        insert(&rootPtr, i);
    }

    traversal(rootPtr);
    
    for (int i=0; i<5; i++){
        delete(&rootPtr);
    }
    return 0;
}