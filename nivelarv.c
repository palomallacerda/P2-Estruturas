#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int elemento;
    struct tree *left;
    struct tree *right;
}tree;

tree *inserir(tree *raiz, int elem)
{
    if (raiz == NULL)
    {
        raiz = (tree*) malloc(sizeof(tree));
        raiz->elemento = elem;
        raiz->right = NULL;
        raiz->right = NULL;
        return raiz;
    }
    else{
        if (elem < raiz->elemento)
        {
            raiz->left = inserir(raiz->left, elem);
        }
        else if (elem > raiz->elemento)
        {
            raiz->right = inserir(raiz->right, elem);
        }
    }
}

void display(tree *raiz)
{
    if (raiz == NULL)
    {
        printf("(NULL)");
    }
    else{
        printf("(");
        display(raiz->left);
        printf(", %d ,", raiz->elemento);
        display(raiz->right);
        printf(")");
    }
}
int nivel(tree *raiz, int e, int d)
{
    if (raiz == NULL)
    {
        return -1;
    }
    else
    {
        e = 1+nivel(raiz->left, e, d);
        d = 1 + nivel(raiz->right, e, d);
        if (e > d)
        {
            return e;
        }
        else return d;
        
    }
}
int main()
{
    tree *raiz;
    raiz = inserir(raiz, 1);
    raiz = inserir(raiz, 0);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 4);
    display(raiz);
    printf("\n");
    int n = nivel(raiz, -1, -1);
    printf("Nível %d\n", n);
    return 0;
}