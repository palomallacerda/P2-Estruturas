#include <stdio.h>
#include <stdlib.h>
/*estrutura de uma fila */
typedef struct no{
    int elemento;
    struct no *prox;
}no;

typedef struct fila{ /*armazenando o inicio e o fim*/
    no *inicio;
    no *fim;
}fila;

void inserir(int dado, fila *f) /*inserindo o dado, e levando como parametro o inicio e fim da fila*/
{
    no *ptr = (no*) malloc(sizeof(no)); /*alocando memoria para o no*/
    if (ptr == NULL) 
    {
        printf("Memória indisponível\n");
        return; 
    }
    else
    {
        ptr->elemento = dado;  
        ptr->prox = NULL; /*garantindo que o proximo sempre recebera nulo e não lixo de memoria*/
        if (f->inicio == NULL && f->fim == NULL) /*caso esteja inserindo primeiro elemento da fila*/        {
            f->inicio = ptr;
        }
        else{
            f->fim->prox = ptr;
        }

        f->fim = ptr;
        return;
    }
}
 
no  *retirar(fila *f) /*recebendo inicio e fim da fila*/
{   
    no *ptr = f->inicio;  /*comeca a retirar do inciio da fila*/
     if (f->inicio == f->fim)
    {
        printf("aqui Elemento %d retirado\n", ptr->elemento);
        free(f->inicio);
        f->inicio = NULL;
        f->fim = NULL;
        return f->inicio;
    }
    else 
    {
        printf("Elemento %d retirado\n", ptr->elemento);
        ptr = f->inicio;
        f->inicio= f->inicio->prox;
        free(ptr);
        return f->inicio;
    }
}
void imprimi(no *ptr)
{

    if (ptr != NULL)
    {
        printf("%d->", ptr->elemento);
        ptr = ptr->prox;
        imprimi(ptr);
    }
    else {
        printf("NULL\n");
       }
    
}

int main()
{
    fila *f1 = (fila*) malloc(sizeof(fila));
    if (f1 == NULL)
    {
        printf("Não foi possivel alocar memória.\n");
    }
    else
    {
        f1->inicio = NULL;
        f1->fim = NULL;
        if (f1->inicio == f1->fim)
        {
            inserir(10, f1);    
        }
        
        inserir(20, f1);    
        inserir(30, f1);
        inserir(40, f1);
        no *aux = f1->inicio;
        imprimi(aux);
        f1->inicio = retirar(f1);
        aux = f1->inicio;
        imprimi(aux);
    }
    
    return 0;
}
