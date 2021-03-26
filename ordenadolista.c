#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct lista
{
    int number;
    char nome[40];
    struct lista *next;
}lista;
lista *inserir(lista *head)
{
    int elem;
    char nome[40];
    printf("Insira o número: ");
    scanf("%d", &elem);
    getchar();
    printf("Insira o nome: ");
    scanf("%s", nome);
    lista *new;
    new = (lista*)malloc(sizeof(lista));
    if (new == NULL) return head;
    
    if (head == NULL) /*inserre 1 elemento*/
    {
        new->number = elem;
        strcpy(new->nome, nome);
        new->next = NULL;
        head = new;
        return head;
    }
    else
    {
        lista *aux = head;
        while (aux->next != NULL && elem > aux->number)
        { 
            aux = aux->next;
        }

        if (aux->next == NULL) /*O numero a inserir é maior que todos */
        {   
           
            if (elem > aux->number)
            {
                new->next = NULL;
                new->number = elem;
                strcpy(new->nome, nome);
                aux->next = new;         
            }
            else
            {
                new->number = aux->number;
                strcpy(new->nome, aux->nome);
                new->next = aux->next;
                aux->number = elem;
                strcpy(aux->nome, nome);
                aux->next = new;
            }

        }else{
            new->number = aux->number;
            strcpy(new->nome, aux->nome);
            new->next = aux->next;
            aux->number = elem;
            strcpy(aux->nome, nome);
            aux->next = new;
        }
        return head; 
    }
}
lista *display(lista *head)
{  
    if (head == NULL)
    {
        printf("\n########### NULL ###########\n");
    }
    else{
        printf("\nNumber: %d\n", head->number);
        printf("Nome: %s", head->nome);
        head = head->next;
        return display(head);
    } 
}

int main()
{   
    lista *head = NULL;
    head = inserir(head);
    head = inserir(head);
    head = inserir(head);
    display(head);
    return 0;
}
