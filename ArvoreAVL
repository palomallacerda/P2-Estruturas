#include <stdio.h>
#include <stdlib.h>
/*nivel não está balanceando assim que pega o novo elemento da arvore*/
/*tentar inserir o nivel na função de inserir*/
typedef struct tree{
    int elemento, h;
    struct tree *left;
    struct tree *right;
}tree;

void display(tree *raiz) /*pós ordem*/
{
    if (raiz == NULL)
    {
        printf("(NULL)");
    }
    else   
    {   
        printf("(");
        printf("%d, ", raiz->elemento);
        display(raiz->left);
        printf(",");
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
int fator_balanceamento(int n_left, int n_right, tree *raiz) 
{
    if (raiz == NULL) return 0;
    else
    {
        return n_left-n_right;      
    }
}
tree *r_right(tree *l) {
	tree *aux = NULL;
	if(l != NULL && l->left != NULL) {
		aux = l->left;
		l->left = aux->right;
		aux->right = l;
	}
    aux->h = nivel(aux, -1, -1);
    l->h = nivel(l, -1, -1);
	return aux;
}

tree *r_left (tree *l) {
	tree *aux = NULL;
	if(l != NULL && l->right != NULL) {
		aux = l->right;
		l->right = aux->left;
		aux->left = l;
	}
    aux->h = nivel(aux, -1, -1);
    l->h = nivel(l, -1, -1);
	return aux;
}

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
        else 
        {
            raiz->right = inserir(raiz->right, elem);
        }
    }
}


int main()
{
    tree *raiz = NULL, *aux;
    int i = 0, number;
    while (scanf("%d", &number)!= EOF )
    { 
        raiz= inserir(raiz, number);
        puts("Sua arvore atual");
        display(raiz);
        puts("");

        int n_left = nivel(raiz->left, -1, -1)+1;
        printf("Nível esquerda: %d\n", n_left);
        int n_right = nivel(raiz->right, -1, -1) +1;
        printf("Nível direita: %d\n", n_right);
        int fb = fator_balanceamento(n_right, n_left, raiz);
        printf("balanced factor:%d\n", fb);

        if(fb == 2 || fb == -2) /*vai ta desbalanceada*/
        { 
            printf("Precisa de balanceamento...\n");
            
    		if(fb == 2) /*direita desbalanceada*/
            {   
                aux = raiz->right;
                int n_left_aux = nivel(aux->left, -1, -1);
                printf("aux-> %d\n", aux->elemento);
                printf("aux esquerda-> %d\n", n_left_aux);
                int n_right_aux = nivel(aux->right, -1, -1);
                printf("aux direita-> %d\n", n_right_aux);

                int fb_aux = fator_balanceamento(n_right_aux, n_left_aux, aux);
                printf("fb_aux-> %d\n", fb_aux);
                if(fb_aux == 1) {
                    raiz->right = r_right(aux);
                }
                else if (fb_aux = -1)
                {
                    raiz->right = r_left(aux);
                }

                raiz = r_left(raiz);
                i= 1;
            
        	  i= 1;
            } 
            else if(fb == -2) /*esquerda desbalanceada*/
            {
                aux = raiz->left;
                int n_left_aux = nivel(aux->left, -1, -1);
                int n_right_aux = nivel(aux->right, -1, -1);
                int fb_aux = fator_balanceamento(n_right_aux, n_left_aux, aux);
                
                if(fb_aux == 1) {
                    raiz->left = r_left(aux);
                }
                else if (fb_aux = -1)
                {
                    raiz->right = r_right(aux);
                }
                raiz = r_right(raiz);
                i= 1;
            }
        if (i != 0)
        { 
            puts("Balanceada");
            display(raiz);
            puts("");
            break;
        }
    
    }
}
     
    return 0;
}
