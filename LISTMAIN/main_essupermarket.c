#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXTEMP 4
#define MINTEMP 1
#define TEMPMAX 20
typedef struct coda{
    int temposerv;
    int pos;
    struct coda *next;
} Coda;
int is_empty(struct coda *head) { // processo, non pila
    if (head == NULL) return 1;
    else return 0;
}
void enqueue(struct coda **head, struct coda **tail, struct coda *element) {//funzione che aggiunge un elemento alla coda
    if (is_empty(*head))
        *head = element;
    else
        (*tail)->next = element;
    *tail = element;
    element->next = NULL;
}
struct coda *dequeue(struct coda **head, struct coda **tail) { // toglie il un elemento della coda
    struct coda *ret = *head;
    if (is_empty(*head))
        return NULL;
    else
        *head = ret->next;
    if (*head == NULL)
        *tail = NULL;
    return ret;
}
void printcoda(Coda *head){//stampa i dati della coda
    while(head!=NULL){
        printf("posizione %d,tempo servizio %d\n",head->temposerv,head->pos);
        head=head->next;
    }
}
void freeCoda(Coda * coda) {//fa la free della coda
    if(coda->next != NULL)
        freeCoda(coda->next);
    free(coda);
}
int main( )
{
    Coda *clienti = NULL; // (Coda *) malloc(sizeof(Coda));
    //clienti=(Coda *) malloc(sizeof (Coda));
    //Coda *ultimo = NULL; //(Coda *) malloc(sizeof (Coda));
    //ultimo=clienti;

    int temp=0,count=0,temponext=0;
    //clienti->next=NULL;
    //ultimo->next=NULL;
    srand(time(NULL));
    //temp=rand()%(MAXTEMP-MINTEMP+1)+MINTEMP;
    temponext=rand()%(MAXTEMP-MINTEMP+1)+MINTEMP;
    //clienti->pos=count;
    //clienti->temposerv=temp;
    //count=1;
    for(int k=0;k<TEMPMAX;k++){
        if(temponext==k){
            Coda *newcliente =(Coda *) malloc(sizeof (Coda));
            newcliente->next=NULL;
            newcliente->temposerv=rand()%(MAXTEMP-MINTEMP+1)+MINTEMP;
            newcliente->pos=count;
            newcliente->next=NULL;
            enqueue(&clienti,&ultimo,newcliente);
            temponext=k+rand()%(MAXTEMP-MINTEMP+1)+MINTEMP;
            count++;
        }
        if(clienti->temposerv==k){
            //dequeue(&clienti,&ultimo);
            printf("cliente servito");
            clienti->temposerv=k+rand()%(MAXTEMP-MINTEMP+1)+MINTEMP;
        }
        printf("tempo %d\n",k);
        printcoda(clienti);
    }
    freeCoda(clienti);
}
