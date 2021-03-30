#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int raiz;
    struct arvore *left;
    struct arvore *right;
}arvore;
arvore *inserir(arvore *raiz, int elem) /*inserindo na árvore*/
{
    if (raiz == NULL)
    {
        raiz = (arvore*) malloc(sizeof(arvore));
        raiz->raiz = elem;
        raiz->left = NULL;
        raiz->right = NULL;
        return raiz;
    }
    else if (raiz->raiz < elem) /*direita*/
    {
        raiz->right = inserir(raiz->right, elem);
    }
    else 
    {
        raiz->left = inserir(raiz->left, elem);
    }
}


void display(arvore *raiz)
{
    if (raiz == NULL)
    {
        printf("(NULL)");
    }
    else   
    {   
        printf("(");
        display(raiz->left);
        printf(", %d ,", raiz->raiz);
        display(raiz->right);
        printf(")");
    }
}


int main()
{
    arvore *elem = NULL;
    elem = inserir(elem, 8);
    elem = inserir(elem, 4);
    elem = inserir(elem, 12);
    display(elem);
    return 0;
}
