int consultar(arvore *raiz, int elem)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        if (raiz->raiz == elem)
        {
            return 1;
        }
        else
        {
            if (elem < raiz->raiz)
            { 
                return consultar(raiz->left, elem);
            }
            else return consultar(raiz->right, elem);
            
        }   
    }
}
