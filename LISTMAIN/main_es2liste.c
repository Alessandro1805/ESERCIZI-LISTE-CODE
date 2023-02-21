#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char *name;
    struct node *next;
} User;

void carica(User *list) {

}
void stampa(User *list) {
    while(list->next!=NULL){
        printf("%s\n",list->name);
            list = list->next;
        }
}
void stampa1(User *list) {
    if(list!=NULL){
        printf("%s\n",list->name);
        list=list->next;
        stampa(list);
    }
}
void dealloca1(User *list) {
    User *temp;
    while(list!=NULL){
        temp=list;
        list=list->next;
        free(temp);
    }
}
void dealloca(User *list) {
    User *temp;
    if(list!=NULL){
        temp=list->next;
        free(list);
        dealloca(temp);
    }
}
void conta(User *list) {
    int i=0;
    while(list->next!=NULL){
        i++;
        list=list->next;
    }
    printf("%d\n",i);
}
int conta1(User *list,int *i) {
    if (list != NULL) {
        list = list->next;
        conta1(list,&i);
    }
}
void carica1(User *list, User *temp) {
    printf("inserisci un nome");
    fflush(stdin);
    gets(list->name);
    printf("%s\n", list->name);
    printf("%p\n", temp);
    printf("%p\n", list->next);
    printf("inserisci un nome");
    fflush(stdin);
    gets(temp->name);
    list->next = temp;
    printf("%s\n", list->next->name);
    temp->next = NULL;
    printf("inserisci un nome");
    fflush(stdin);
    gets(temp->name);
    temp->next = NULL;
    list->next->next = temp;
    printf("%s\n", list->next->next->name);
}

int main() {
    User *list, *temp;
    User *tempo;
    int i=0;
    char nome[20];
    list = (User *) malloc(sizeof(User));
    tempo = (User *) malloc(sizeof(User));
    tempo=list;
    do {
        printf("inserisci un nome");
        fflush(stdin);
        gets(nome);
        if(strcmp(nome,"fine")!=0){
            strcpy(list->name,nome);
            list=list->next;
        } else {
            list->next=NULL;
        }
    } while (strcmp(nome, "fine") != 0);
    stampa(tempo);
    dealloca(tempo);
    stampa(tempo);
}

