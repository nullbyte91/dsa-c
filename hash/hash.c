#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_SIZE 20

struct elt{
    int data;
};

struct hash{
    struct elt* data;
    struct hash* next;
};

int
hashFunction(int data){
    return data  % MAX_SIZE;
}

void
insert(struct hash* hashT[], int data){
    int key = hashFunction(data);
    struct hash* ptr = hashT[key];
    if (ptr == NULL){
        struct elt* node = malloc(sizeof(struct elt));
        assert(node);

        node->data = data;

        struct hash* table = malloc(sizeof(struct hash));
        table->data = node;
        table->next = hashT[key];
        hashT[key] = table;
    } else {
        printf("%d - is duplicate key\n", data);
        return;
    }
}

void
showHash(struct hash* hashT[]){
    struct hash* ptr;
    for (int i=0; i<MAX_SIZE; i++){
        if (hashT[i] != NULL){
            ptr = hashT[i];
            while(ptr != NULL){
                printf("%d ", ptr->data->data);
                ptr = ptr->next;
            }
        }
    }
}

int 
main(int argc, char** argcv){
    struct hash* hashTable[MAX_SIZE];
    
    // Assign NULL all the index of HashTable
    for (int i=0; i<MAX_SIZE; i++){
        hashTable[i] = NULL;
    }

    for (int i=0; i<5; i++){
        insert(hashTable, i);
    }

    insert(hashTable, 2);
    insert(hashTable, 6);
    
    //show hash Table content
    showHash(hashTable);
    return 0;
}