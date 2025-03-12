#include <stdio.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;


void printLinkedList(Node *head){
    Node *cur = head;

    while(cur != NULL){
        printf("NodeVal: %d  ADDRS: %p  next: %p", cur->value, cur, cur->next);
        printf("\n");
        cur = cur->next;
    }
}

int main(){
    Node n1, n2, n3;
    Node *HEAD;

    n1.value = 10;
    n2.value = 15;
    n3.value = 20;
    HEAD = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    printLinkedList(HEAD);

}
