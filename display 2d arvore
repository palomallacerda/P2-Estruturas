#define COUNT 10

void display(tree *raiz, int space)
{   
    if (raiz == NULL) return;
    else{
       
        space += COUNT;
        display(raiz->right, space);
        printf("\n");
        for (int i = COUNT; i < space; i++)
           printf(" ");

        printf("%d\n", raiz->elemento);
        display(raiz->left, space);
       
    }
}

 display(raiz, 0);
