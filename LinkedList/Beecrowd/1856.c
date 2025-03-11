#include <stdlib.h>
#include <stdio.h>

// Time limit exceeded
// Time limit exceeded
// Time limit exceeded
// Time limit exceeded
// Time limit exceeded

typedef struct ListNode {
    int value;
    struct ListNode *next;
} ListNode;


void insert(int a, int b, ListNode *cur){
	ListNode *add = (ListNode *)malloc(sizeof(ListNode));
	add->value = a;
	while(cur != NULL){
		if(cur->value == b){
			ListNode *aux = cur->next;
			add->next = aux;
			cur->next = add;
			break;
		}
		cur = cur->next;
	}
}

ListNode* removeNode(int a, ListNode *cur){
	ListNode *head = cur;
	if(a == cur->value){ // Se a == head.value;
		return cur->next;
	}

	while(cur->next != NULL){
		if(cur->next->value == a){
			cur->next = cur->next->next;
			break;
		} 
		cur = cur->next;
	}

	return head;

}

int calcDist(int a, int b, ListNode *cur){
	int cont = 0;
	int foundA = 0;
	while(cur != NULL){
		if(cur->value == a && foundA == 0){
			foundA = 1;
		} else if(cur->value == b){
			return cont;
		} else if(foundA == 1){
			cont++;
		}
		cur = cur->next;
	}
}

int main(){
	ListNode *head = NULL, *tmp = NULL;
	int n, input, q, a,b;
	char op;

	scanf("%d", &n);
	while(n--){ // Le a lista inicial
		scanf("%d", &input);
		ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
		newNode->value = input;
		newNode->next = NULL;

		if(!head){
			head = newNode;
			tmp = newNode;
		}else {
			tmp->next = newNode;
			tmp = tmp->next;
		}
	}

	scanf("%d", &q);
	while(q--){
		scanf(" %c", &op);

		if(op == 'I'){
			scanf("%d %d", &a, &b);
			tmp = head;
			insert(a,b, tmp);
		} else if(op == 'R'){
			scanf("%d", &a);
			tmp = head;
			head = removeNode(a, tmp);
		}  else if(op == 'Q'){
			scanf("%d %d", &a, &b);
			tmp = head;
			int dist = calcDist(a, b, tmp);
			printf("%d\n", dist);
		}
	}

	return 0;
}