#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} Queue;

Queue* createQueue(int n){
    Queue *queue = malloc(sizeof(Queue));
    queue->head = NULL;

    for(int i = 1; i<=n; i++){
        Node *newNode = malloc(sizeof(Node));
        newNode->value = i;
        newNode->next = NULL;

        if(queue->head == NULL){
            queue->head = newNode;
            queue->tail = newNode;
        } else {
            queue->tail->next = newNode;
            queue->tail = queue->tail->next;
        }
    }

    return queue;
}

void resolve(Queue *q){
    printf("Discarded cards: ");
    int isFirst = 1;
    while(q->head != q->tail){
        printf("%d", q->head->value);
        Node *discard = q->head;
        q->head = q->head->next;
        free(discard);
        
        if(q->head == q->tail) { break;}

        q->tail->next = q->head;  
        q->tail = q->head; 
        q->head = q->head->next;
        q->tail->next = NULL;
        
        printf(", ");
    }

    printf("\n");
    printf("Remaining card: %d", q->head->value);
}

int main(){

    int input;
    while(1){
        scanf("%d", &input);
        if(input == 0){break;}

        Queue *queue = createQueue(input);
        resolve(queue);
        printf("\n");
    }
    return 0;
}