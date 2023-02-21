#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>

typedef struct  node{
    int  valore;
    char nome[20];
    struct  node* next;//indirizzo del nodo successivo
}Node;


void close(Node* l) {
    if(l!=NULL){
        Node *temp=l->next;
        l->next=NULL;
        free(l);
        close(temp);
    }

}
void inserimento(Node **head, Node *element){
    Node *curr=*head;
    Node *prev = NULL;

    while (curr != NULL){
        if (element->valore >= curr->valore)
            break;
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL){
        *head = element;
    }else {
        prev->next = element;
    }

    element->next=curr;
}

void stampa(Node *l){

    int k=0;
    //printf("STAMPA CON PROC: \n");
    while (l!=NULL && k<5)//puntatore alla lista diversa da NULL
    {
        printf("\n%s - %d \n",l->nome, l->valore);
        l=l->next;                                          //assegna ad l il campo successivo, all'ultima iterazione assegna il campo NULL ed esce dal ciclo
        k++;
    }
}

void dealloca(Node *l){
    Node* tmp;
    if(l!=NULL)
    {
        tmp->next = l->next;
        free(l);
        dealloca(tmp);
    }
}
void cancellaNodo(Node *lista,int ind){
    Node *temp;
    temp= (Node*)malloc(sizeof(Node));
    if(ind<5){
        temp=lista->next;
        ind++;
        cancellaNodo(temp,ind);
    }else{
        close(temp);
    }
}
int  main()
{
    int n;
    char nom[20];
    Node* lista;                                            //tipo a puntatore a node
    lista = NULL;
    Node* l;
    int k=0;
    l = lista;
    do
    {
        printf("Inserisci il valore del viodeogioco o -1 per  terminare\n");
        scanf("%d",&n);

        if (n!=-1){
            printf("Inserisci il nome: \n");
            fflush(stdin);
            gets(nom);
        }

        if (n!=-1){
            Node *elem;
            elem = (Node*)malloc(sizeof(Node));

            elem->valore=n;
            strcpy(elem->nome,nom);
            elem->next=NULL;

            inserimento(&lista,elem);
        }

    } while (n>=0);
    stampa(l);
    //cancellaNodo(lista,0);
    dealloca(lista);

    return  0;
}