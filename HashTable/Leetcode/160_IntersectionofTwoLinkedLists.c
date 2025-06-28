typedef struct AnsNode {
    struct ListNode* node;
    struct AnsNode* next;
} AnsNode;

#define TABLE_SIZE 30

struct AnsNode* hash_table[TABLE_SIZE];

void init_hash_table(){
    for(int i = 0; i<TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
}

unsigned int hash(struct ListNode* ptr) {
    return ((unsigned long)ptr) % TABLE_SIZE;
}

void insert_in_hash_table(struct ListNode *node){
    unsigned int index  = hash(node);
    AnsNode* ans_node = malloc(sizeof(AnsNode));
    ans_node->node = node;
    ans_node->next = NULL;

    if(hash_table[index] == NULL){
        hash_table[index] = ans_node;
    } else {
        AnsNode* cop = hash_table[index];
        while(cop->next != NULL){
            cop = cop->next;
        }
        cop->next = ans_node;
    }
}

AnsNode* find_in_hash_table(struct ListNode *node){
    unsigned int index = hash(node);
    if(hash_table[index] == NULL){
        return NULL;
    } else {
        AnsNode* cop = hash_table[index];
        while(cop!= NULL){
            if(cop->node == node){
                return cop;
            }
            cop = cop->next;
        }
        return NULL;
    }
}



struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    init_hash_table();
    while(headA != NULL){
        insert_in_hash_table(headA);
        headA = headA->next;
    }

    while(headB != NULL){
        AnsNode* ans = find_in_hash_table(headB);
        if(ans != NULL){
            return ans->node;
        }
        headB = headB->next;
    }
    return NULL;
}