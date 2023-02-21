#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include <stdbool.h>
//inserire in una lista il nome di 1 videogioco e il suo valore quando il contatore dei videogiochi inseriti
//arriva a 5 è necessario eliminare l'ultimo elemento della lista che viene ordinata ad ogni inserimento
typedef struct  node{//definizione della struttura con tutte le variabili
    int  valore;
    char nome[20];
    struct  node* next;//indirizzo del nodo successivo richiamiaìmo
                      // il nome della struct in minuscolo in quannto all'atto della compilazione viene letto il programma con un metodo top downe il nome in maiuscolo nn è stato ancora associato
}Node;


void stampa(Node *l){//stampa della lista
    if (l!=NULL)//puntatore alla lista diversa da NULL
    {
        printf(" %d \n", l->valore);
        l=l->next;//assegna ad l il campo successivo, all'ultima iterazione assegna il campo NULL ed esce dal ciclo
        stampa(l);
    }
}
void stampa1(Node *l){//stampa della lista
    while (l!=NULL)//puntatore alla lista diversa da NULL
    {
        printf("\n%s - %d \n",l->nome, l->valore);
        l=l->next;//assegna ad l il campo successivo, all'ultima iterazione assegna il campo NULL ed esce dal ciclo
    }
}
void dealloca(Node *l){
    Node* temp;
    if(l!=NULL)
    {
        temp->next = l->next;
        free(l);
        dealloca(temp);
    }
}

void inserimento(Node **head, Node *element){//funzione presa da un codice del prof conradi
    Node *curr=*head;                        //che inserisce un nuovo elemento in ordine in una lista
    Node *prev = NULL;


    while (curr != NULL){//cicla finche curr nn è uguale a null
        if (element->valore >= curr->valore)//controlla se il nuobo node ha valore > della testa e lo mette come testa altrimenti continua il controllo
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
void insertHead(Node** head, int new_valore) {
    Node* new_testa = (Node*) malloc(sizeof(Node));
    new_testa->valore = new_valore;
    new_testa->next = *head;
    *head = new_testa;
}
void insertTail(Node*head, int new_valore) {
    Node* new_tail = (Node*) malloc(sizeof(Node));
    new_tail->valore = new_valore;
    head->next = new_tail;
    new_tail->next=NULL;

}
int  main()
{
    int n;    //variabile per inserimento
    int ind = 0;//conta il numero di elementi inseriti
    char nom[20];
    Node* lista;//tipo a puntatore a node
    lista = (Node*) malloc(sizeof(Node));
    lista->valore=3;
    lista->next = NULL;
    Node* temp;
    temp=lista;
    printf("a");
    //inserisce elementi fiche il valore di n non è ugale a -1
    do{
        printf("Inserisci il valore del videogioco o -1 per stoppare l'inserimento\n");
        scanf("%d",&n);
        if (n!=-1){
            insertTail(lista,n);
            }

    } while (n>=0);
    stampa(lista);//stampa la lista
    dealloca(lista);//dealloca la lista

    return  0;
}