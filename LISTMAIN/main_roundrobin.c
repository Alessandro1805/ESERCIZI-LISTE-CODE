#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXECUTE "ex"
#define NEW "new"
#define WAIT "wi"
#define LUNG 20
#define CPU_TIME 30
typedef struct processo {
    int pid;
    char stato[LUNG];
    int extime;
    struct processo *next; // processo, non pila
} Proces;

int is_empty(struct processo *head) { // processo, non pila
    if (head == NULL) return 1;
    else return 0;
}
void enqueue(struct processo **head, struct processo **tail, struct processo *element) {//funzione che aggiunge un elemento alla coda
    if (is_empty(*head))
        *head = element;
    else
        (*tail)->next = element;
    *tail = element;
    element->next = NULL;
}
struct processo *dequeue(struct processo **head, struct processo **tail) { // toglie il un elemento della coda
    struct processo *ret = *head;
    if (is_empty(*head))
        return NULL;
    else
        *head = ret->next;
    if (*head == NULL)
        *tail = NULL;
    return ret;
}
void esegui(Proces **head, Proces **tail, Proces **headtl, Proces **tailtl, int tempo) {
    while (!is_empty(*head)) {
        Proces* processo = dequeue(head, tail); // prendi il primo processo
        processo->extime -= tempo; // togli il tempo
        if (processo->extime <= 0) {  // modifica con *, sostituito da processo
            strcpy(processo->stato, EXECUTE);  // modifica con *, sostituito da processo
            enqueue(headtl, tailtl, processo);
        } else {
            enqueue(head, tail, processo);
        }
    }
}
void printcoda(Proces *head){//stampa i dati della coda
    while(head!=NULL){
        printf("pid processo %d,stato proceso %s,tempo %d",head->pid,head->stato,head->extime);
        head=head->next;
    }
}

void freeCoda(Proces * coda) {//fa la free della coda
    if(coda->next != NULL)
        freeCoda(coda->next);
    free(coda);
}

int main() {
    Proces *fistproc = (Proces *) malloc(sizeof(Proces));
    Proces *tail = fistproc;
    Proces *headrl = NULL;
    Proces *tailrl = NULL;
    Proces *headex = NULL;
    Proces *tailex = NULL;
    int pid, extime, num = 0;
    printf("inserici codice identificativo del processo");
    scanf("%d", &pid);
    printf("inserisci il tempo di esecuzione");
    scanf("%d", &extime);
    fistproc->next = NULL;
    fistproc->extime = extime;
    fistproc->pid = pid;
    strcpy(fistproc->stato, NEW);
    while (pid != -1) {
        num++;
        printf("inserisci un il pid del processo -1 per stoppare");
        scanf("%d", &pid);
        if (pid != -1) {
            Proces *newproc = (Proces *) malloc(sizeof(Proces));
            newproc->next = NULL;
            newproc->pid = pid;
            printf("inserisci il tempo di esecuzione");
            //newproc->extime = 5;
            scanf("%d", &newproc->extime);
            strcpy(newproc->stato, NEW);
            enqueue(&fistproc, &tail, newproc); // togli la &, non è **, solo *
        }
    }
    Proces *temprl;
    while(!is_empty(fistproc)) {
        temprl = dequeue(&fistproc, &tail);
        strcpy(temprl->stato,WAIT);
        enqueue(&headrl, &tailrl, temprl);
    }

    esegui(&headrl, &tailrl, &headex, &tailex, CPU_TIME);
    printcoda(headex);
    freeCoda(headex);
    tailex = NULL;

    return 0;
}