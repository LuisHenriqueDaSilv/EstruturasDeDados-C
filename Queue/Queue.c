#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct {
    node *head;
    node *tail;   
} Queue;

Queue *init_queue();
bool enqueue(Queue *q, int value);
bool isEmpty(Queue *q);
bool dequeue(Queue *q, int *value);

int main(){

    Queue *queue = init_queue();
    if(queue == NULL){
        printf("Erro ao iniciar a fila");
        return 1;
    }

    for(int i =0; i<10; i++){
        enqueue(queue, i);
    }
    
    for(int i =0; i<10; i++){
        int value;
        dequeue(queue, &value);
        printf("%d ", value);
    }

    return 0;
}

Queue *init_queue(){
    Queue *queue = malloc(sizeof(Queue));
    if(queue == NULL){
        return NULL;
    }
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

bool enqueue(Queue *q, int value){
    if(q == NULL ){
        return false;
    }
    node *newNode  =malloc(sizeof(node));
    if(newNode == NULL){
        return false;
    }

    newNode->value = value;
    newNode->next = NULL;
    if(isEmpty(q)){
        q->tail = newNode;
        q->head = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = q->tail->next;
    }

    return true;
}

bool dequeue(Queue *q, int *value){
    if(q == NULL || isEmpty(q)){
        return false;
    }
    *value = q->head->value;
    q->head = q->head->next;
    return true;
}

bool isEmpty(Queue *q){
    return q->head == NULL;
}