#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    char* name;
    int age;
} People;

People* hash_table[TABLE_SIZE];

void init_hash_table(){
    for(int i = 0; i< TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
}

unsigned int hash(char* name){
    int length = strlen(name);
    unsigned int hash = 0;
    for(int i = 0; i<length; i++){
        hash+=name[i];
        hash=(hash*name[i])%TABLE_SIZE;
    }
    return hash;
}

void print_table(){
    for(int i=0; i<TABLE_SIZE; i++){
        if(hash_table[i] != NULL){
            printf("%d %s\n", i, hash_table[i]->name);
        } else {
            printf("%d -----\n", i);
        }
    }

    printf("\n\n");
}

int hash_table_insert(People *p){
    unsigned int index = hash(p->name);
    if(hash_table[index] != NULL){
        return 0;
    } else {
        hash_table[index] = p;
    }
}
People *hash_table_lookup(char *name){
    int index = hash(name);
    if(hash_table[index] !=NULL && strcmp(hash_table[index]->name, name) == 0){
        return hash_table[index];
    }
    return  NULL;
}

People *hash_table_remove(char *name){
    int index = hash(name);
    if(hash_table[index] !=NULL && strcmp(hash_table[index]->name, name) == 0){
        People* temp = hash_table[index];
        hash_table[index] = NULL;
        return temp;
    }
    return  NULL;
}

int main(){

    init_hash_table();
    print_table();

    People Luis = {"Luis", 10}; 
    People Jacob = {"Jacob", 14}; 
    People Vitoria = {"Vitoria", 15}; 
    People Amanda = {"Amanda", 16};
    
    hash_table_insert(&Luis);
    hash_table_insert(&Jacob);
    hash_table_insert(&Vitoria);
    hash_table_insert(&Amanda);
    print_table();

    People* remove = hash_table_remove("Luis");
    if(remove != NULL){
        printf("Encontrado: %s %d\n", remove->name, remove->age);
    } else {
        printf("Não encontrado!\n");
    }
    People* find = hash_table_lookup("Luis");
    if(find != NULL){
        printf("Encontrado: %s %d\n", find->name, find->age);
    } else {
        printf("Não encontrado!\n");
    }

    print_table();



    // printf("Luis: %u\n",hash("Luis"));
    // printf("Jacob: %u\n",hash("Jacob"));
    // printf("Vitoria: %u\n",hash("Vitoria"));
    // printf("Amanda: %u\n",hash("Amanda"));

    // printf("Luis: %u\n",hash("Luis"));
    // printf("Jacob: %u\n",hash("Jacob"));
    // printf("Vitoria: %u\n",hash("Vitoria"));
    // printf("Amanda: %u\n",hash("Amanda"));
    return 0;

}