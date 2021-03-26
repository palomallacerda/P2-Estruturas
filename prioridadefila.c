/*Use o compilador Compilador GCC*/ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no2{
    char nome[40];
    int cont;
    struct no2 *next;
}no2;

typedef struct fila2{
    no2 *first;
    no2 *last;
}fila2;

typedef struct no1{
    char nome[40];
    int cont;
    struct no1 *next;
}no1;

typedef struct fila1{
    no1 *first;
    no1 *last;
}fila1;

typedef struct no{
    char nome[40];
    int cont;
    struct no *next;
}no;

typedef struct fila{
    no *first;
    no *last;
}fila;

void adding(fila *f, int prior, char nome[])
{
    no *pessoa = (no*)malloc(sizeof(no));
    if (!pessoa){
        printf("Não foi possível alocar memoria\n");
        return;
    }
    else
    { 
        strcpy(pessoa->nome, nome); 
        pessoa->cont = prior;
        pessoa->next = NULL;
        if (f->first == NULL && f->last == NULL) /*primeiro elemento da fila*/
        {
            f->first = pessoa;
        }
        else{
            f->last->next = pessoa;
        }
        f->last = pessoa;
        return;
    }
}
void adding1(fila1 *f, int prior, char nome[])
{
    no1 *pessoa = (no1*)malloc(sizeof(no1));
    if (!pessoa){
        printf("Não foi possível alocar memoria\n");
        return;
    }
    else
    {
        strcpy(pessoa->nome, nome); 
        pessoa->cont = prior;
        pessoa->next = NULL;
        if (f->first == NULL && f->last == NULL) /*primeiro elemento da fila*/
        {
            f->first = pessoa;
        }
        else{
            f->last->next = pessoa;
        }
        f->last = pessoa;
        return;
    }
}
void adding2(fila2 *f, int prior, char nome[])
{
    no2 *pessoa = (no2*)malloc(sizeof(no2));
    if (!pessoa){
        printf("Não foi possível alocar memoria\n");
        return;
    }
    else
    {
        strcpy(pessoa->nome, nome); 
        pessoa->cont = prior;
        pessoa->next = NULL;
        if (f->first == NULL && f->last == NULL) /*primeiro elemento da fila*/
        {
            f->first = pessoa;
        }
        else{
            f->last->next = pessoa;
        }
        f->last = pessoa;
        return;
    }
}

no  *off(struct fila *f1)
{
    no *aux = f1->first;
    if (f1->first == f1->last)
    {
        //printf("Retirando Cliente: %s \n", aux->nome);
        free(f1->first);
        f1->first = NULL;
        f1->last = f1->first;
        return f1->first;
    }
    else
    {
        //printf("Retirando Cliente: %s \n", aux->nome);
        aux = f1->first;
        f1->first = f1->first->next;
        free(aux);
        return f1->first;
    }
}
no1  *off1(struct fila1 *f1)
{
    no1 *aux = f1->first;
  
    if (f1->first == f1->last)
    {
        //printf("Retirando Cliente: %s \n", aux->nome);
        free(f1->first);
        f1->first = NULL;
        f1->last = f1->first;
        return f1->first;
    }
    else
    {
       // printf("Retirando Cliente: %s \n", aux->nome);
        aux = f1->first;
        f1->first = f1->first->next;
        free(aux);
        return f1->first;
    }
}
no2  *off2(struct fila2 *f1)
{
    no2 *aux = f1->first;
    

    if (f1->first == f1->last)
    {
        //printf("Retirando Cliente: %s \n", aux->nome);
        free(f1->first);
        f1->first = NULL;
        f1->last = f1->first;
        return f1->first;
    }
    else
    {
        //printf("Retirando Cliente: %s \n", aux->nome);
        aux = f1->first;
        f1->first = f1->first->next;
        free(aux);
        return f1->first;
    }
}
no *display(no *head, int qtd, fila *f)
{
    
    if (head == NULL || qtd == 4)
    {
        printf("\n");
    }
    else
    {
        printf("\n");
        puts("-------------------- Prioridade 0 --------------------");
        puts("-----------  Diriga-se ao local apropiado ------------");
        printf("Nome: %s\n", head->nome); 
        printf("Prioridade: %d\n", head->cont);
        f->first = off(f);
       return display(head->next, qtd+1, f);
    }
}

no1 *display1(no1 *head, int qtd, fila1 *f1)
{
   
    if (head == NULL || qtd == 4)
    {
        printf("\n");
    }
    else
    {
        printf("\n");
        puts("-------------------- Prioridade 1 --------------------");
        puts("-----------  Diriga-se ao local apropiado ------------");
        printf("Nome: %s\n", head->nome); 
        printf("Prioridade: %d\n", head->cont);
        f1->first = off1(f1);
       return display1(head->next, qtd+1, f1);
    }
}
no2 *display2(no2 *head, int qtd, fila2 *f2)
{
   
    if (head == NULL || qtd == 4)
    {
        printf("\n");
    }
    else
    {
        printf("\n");
        puts("-------------------- Prioridade 2 --------------------");
        puts("-----------  Diriga-se ao local apropiado ------------");
        printf("Nome: %s\n", head->nome); 
        printf("Prioridade: %d\n", head->cont);
        f2->first = off2(f2);
        return display2(head->next, qtd+1, f2);
    }
}
int menu(fila1 *f1, fila *f, fila2 *f2)
{
    puts("--------------------------  Bem vindo ----------------------------");
    puts("----------------- Aguarde você já será atendido ------------------");
    int n, i = 0, prior;
    char nome[40];
    printf("Insira quantas fichas serão necessárias: ");
    scanf("%d", &n);
    while (i < n)
    {
        
        printf("Insira o %dº nome: ", i+1);
        scanf("%s", nome); 
        getchar();
        printf("Insira a prioridade: ");
        scanf("%d", &prior);
        if (prior == 0)
        {
            adding(f, prior, nome);
        
        }
        else if (prior == 1)
        {
            adding1(f1, prior, nome);
        }
        else if (prior == 2)
        {
            adding2(f2, prior, nome);
        }
        else
        {
            printf("Não existe essa prioridade\n");       
            printf("Insira a prioridade entre 0-2: ");
            scanf("%d", &prior);
            if (prior == 0)
            {
                adding(f, prior, nome);
            }
            else if (prior == 1)
            {
                adding1(f1, prior, nome);
            }
            else if (prior == 2)
            {
                adding2(f2, prior, nome);
            }
        } 
        
        i++;
    }
    int qtd = 4;
    int j = 0, k = 0;
    while (k <= n/4)
    {
        if (f != NULL)
        {
            no *aux = f->first;
            display(aux, j, f);
        }
        if (f1 != NULL)
        {
            
            no1 *aux1 = f1->first;
            display1(aux1, j, f1);
        }
        if (f2 != NULL)
        {  
            no2 *aux2 = f2->first;
            display2(aux2, j, f2);
        }        
        k++;
    }
}

int main()
{
    fila *f = (fila*) malloc(sizeof(fila)); 
    fila1 *f1 = (fila1*) malloc(sizeof(fila1));
    fila2 *f2 = (fila2*) malloc(sizeof(fila2));
    if (f1 == NULL || f == NULL || f2 == NULL)
    {
        printf("Não foi possivel alocar memória\n");
    }
    else
    {
        f2->first = NULL; 
        f->last = NULL;
        f1->first = NULL; 
        f1->last = NULL;
        f->first = NULL; 
        f->last = NULL;
        menu(f1, f, f2);     
    }
    return 0;
}
