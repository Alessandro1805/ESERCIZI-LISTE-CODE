#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNG 20
typedef struct pila {
    char parentesi;
    struct pila *next;
} Pila;

int is_empty(struct pila *head) {
    if (head == NULL) return 1;
    else return 0;
}

struct pila *pop(struct pila **head) {
    struct pila *ret = *head;
    if (is_empty(*head))
        return NULL;
    else
        *head = ret->next;
    return ret;
}

void push(struct pila **head, struct pila *element) {
    if (is_empty(*head)) {
        *head = element;
        element->next = NULL;
    } else {
        element->next = *head;
        *head = element;

    }
}

void chiudi(Pila *l) {
    if (l != NULL) {
        Pila *temp = l->next;
        l->next = NULL;
        free(l);
        chiudi(temp);
    }

}

void prin(Pila *l) {
    if (l != NULL) {
        printf("%c\n", l->parentesi);
        prin(l->next);
    }

}

int main() {
    char stringa[LUNG] = "{[(allu)]}";
    Pila *parentesi = (Pila *) malloc(sizeof(Pila));
    parentesi->next=NULL;
    for (int k = 0; k < LUNG; k++) {
        if (stringa[k] == '{' || stringa[k] == '[' || stringa[k] == '(') {
            Pila *temp = (Pila *) malloc(sizeof(Pila));
            temp->next = NULL;
            temp->parentesi = stringa[k];
            push(&parentesi, temp);
        }
        if (stringa[k] == ')' || stringa[k] == ']' || stringa[k] == '}') {
            pop(&parentesi);
        }
        prin(parentesi);
    }
    if (parentesi->next==NULL) {
        printf("nessun errore");
    } else {
        printf("mancano chiusure di parentesi");
    }
    chiudi(parentesi);
}