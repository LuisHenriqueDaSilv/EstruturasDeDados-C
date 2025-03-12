#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	char *collection;
	int size;
	int capacity;
} Stack;

Stack *createStack(int capacity){
	Stack *stack = malloc(sizeof(Stack));
	stack->collection = malloc(sizeof(char) * capacity);
	stack->capacity = capacity;
	stack->size=0;
	return stack;	
}

char pop(Stack *stack){
	stack->size--;
	return stack->collection[stack->size];
}

void push(Stack *stack, char value){
	stack->collection[stack->size] = value;
	stack->size++; 
}

bool isValid(char* s) {
	int n = strlen(s);
	if(n < 2){
		return false;
	}
	Stack *stack = createStack(n);
	for(int i = 0; i<n; i++){
		if(s[i] == '(' ||   s[i] == '{' ||   s[i] == '['){
			push(stack, s[i]);
		} else {
			if(stack->size == 0){
				return 0;
			} else {
				char last = pop(stack);
				if(
					(s[i] == ')' && last != '(')|| 
					(s[i] == '}' && last != '{')|| 
					(s[i] == ']' && last != '[')
				){
					return 0;
				}
			}
		}

	}

	return stack->size == 0;
}