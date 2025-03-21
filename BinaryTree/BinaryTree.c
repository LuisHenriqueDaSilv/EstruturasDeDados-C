#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode *createNode(int value){
    TreeNode *node = malloc(sizeof(TreeNode));
    if(node == NULL){
        return NULL;
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main(){
    TreeNode *n1 = createNode(10);
    TreeNode *n2 = createNode(14);
    TreeNode *n3 = createNode(13);
    TreeNode *n4 = createNode(2);
    TreeNode *n5 = createNode(8);
    TreeNode *n6 = createNode(5);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;

    //O código acima cria a seguinte arvore, sendo n1 a "raiz":
    //       n1
    //      /  \ 
    //   n2     n3
    //  / \     /
    // n4  n4  n6

    //Ou seja (Vendo os valores):
    //       10
    //      /  \ 
    //    14    13
    //   / \    /
    //  2   8  5

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    return 0;
}