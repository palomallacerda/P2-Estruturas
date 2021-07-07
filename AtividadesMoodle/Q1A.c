/*usando o compilador GCC para todos os codigos*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    char elemento;
    struct stack *next;
}stack;

stack *inserir_pilha(stack *top)
{
    stack *pilha = (stack*)malloc(sizeof(stack));    
    if(pilha == NULL)
    {
        printf("Erro em alocar a memória.\n");
        return pilha;
    } 
    else 
    {
        if (top == NULL)
        {
            pilha->next = NULL;
            top = pilha;
            return top;    
        }else
        {
            pilha->next = top;
            return pilha;
        }    
    }
}
stack *remover_pilha(stack *pilha)
{
    stack *new = NULL;

    new = pilha;
    pilha = pilha->next; /*indo para o proximo elemento*/
    free(new);

    return pilha;
}
int verificando(int i, char caracter[], int tam, stack *top)
{
    if (i == tam)
    {   
        if (top == NULL)
        {
            return 1;
        }
        else 
        {
            //printf("Erro na posição %d\n", i);
            return 0;
        }
        
    }
    else
    {
        if (caracter[i] == ')' && top == NULL) /*primeiro caracater*/
        {
            //printf("Erro na posição %d\n", i);
            return 0;
        }
        else 
        {
            if (caracter[i] == '(')  
            {
                top = inserir_pilha(top);
            }
            else top = remover_pilha(top);    
            
            return verificando(i+1, caracter, tam, top);
        }
    }
}
int main ()
{    
    stack *top = NULL;
    int i= 0;
    char carac[40];
    
    printf("Insira os caracteres: ");
    scanf("%s", carac);
    getchar();

    int tam = strlen(carac);
    int v = verificando(0, carac, tam, top);

    (v == 1) ? printf("True\n") : printf("False\n"); 

    return 0;
}
