#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNG 20
typedef struct coda {
    int numero;
    struct pila *next;
} Coda;

int is_empty(struct pila *head) {
    if (head == NULL) return 1;
    else return 0;
}

void enqueue(struct coda **head, struct coda **tail, struct coda *element) {
    if (is_empty(*head))
        *head = element;
    else
        (*tail)->next = element;
    *tail = element;
    element->next = NULL;
}
int main() {
    Coda *head = (Coda *) malloc(sizeof(Coda));
    Coda *tail = (Coda *) malloc(sizeof(Coda));
    head->numero = 0;
    tail->numero=10;
    tail->next=NULL;
    head->next=tail;
    int num;
    while (num != -1) {
        printf("inserisci un numero -1 per stoppare");
        scanf("%d", &num);
        if (num != -1) {
            Coda *element = (Coda *) malloc(sizeof(Coda));
            element->next=NULL;
            element->numero=num;
            enqueue(&head,&tail,&element);
        }
    }
}