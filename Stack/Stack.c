#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *collection; // Valores
    int capacity;
    int size; // Quantidade de dados na collection
} Stack;

Stack *createStack(int capacity);
void destroyStack(Stack *stack);
bool isFull(Stack *stack);
bool isEmpty(Stack *stack);
bool push(Stack *stack, int value);
bool peek(Stack *stack, int *item);
bool pop(Stack *stack, int *item);

int main(){
    Stack *stack = createStack(10);
    if(stack == NULL){
        printf("Erro ao criar a stack\n");
        return 1;
    }   

    for(int i = 0; i<11; i++){
        int pushSucess = push(stack, i);
        if(!pushSucess){
            printf("Erro ao adicionar o elemento %d\n", i);
        }
    }

    int item;
    peek(stack, &item);
    printf("Peek: %d\n", item);
    peek(stack, &item);
    printf("Peek: %d\n", item);

    pop(stack, &item);
    printf("pop: %d\n", item);
    pop(stack, &item);
    printf("pop: %d\n", item);


    destroyStack(stack);
    return 0;
}

Stack *createStack(int capacity){
    if(capacity <= 0){
        return NULL;
    }
    Stack *stack = malloc(sizeof(Stack));
    if(stack == NULL){return NULL;}

    int *collection = malloc(sizeof(int) *capacity);
    if(collection == NULL){
        free(stack);
        return NULL;
    }
    stack->collection = collection;
    stack->capacity = capacity;
    stack-> size = 0;
    return stack;
}

void destroyStack(Stack *stack){
    free(stack->collection);
    free(stack);
}

bool isFull(Stack *stack){
    return stack->capacity == stack->size;
}

bool isEmpty(Stack *stack){
    return stack->size == 0;
}

bool push(Stack *stack, int value){
    if(isFull(stack))return false;
    stack->collection[stack->size] = value;
    stack->size++;
    return true;
}

bool peek(Stack *stack, int *item){
    if(isEmpty(stack)){return false;}
    *item = stack->collection[stack->size-1];
    return true;
}

bool pop(Stack *stack, int *item){
    if(isEmpty(stack)){return false;}
    stack->size--;
    *item = stack->collection[stack->size];
    return true;
}