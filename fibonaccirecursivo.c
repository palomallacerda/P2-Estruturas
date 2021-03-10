#include <stdio.h>

int find(int i, int n, int sequencia[])
{
    if (i < n)
    {
        if (i >=2 )
        {          
            sequencia[i] = sequencia[i-1]+sequencia[i-2] ;
            
        }             
        else sequencia[i] = 1;
        find(i+1, n, sequencia);
    }   
}
int imprimir(int i, int n, int sequencia[])
{
    if (i < n)
    {
        printf("%d ", sequencia[i]);
        imprimir(i+1, n, sequencia);
    }
}
int main()
{   
    int n;
    scanf("%d", &n);
    int sequencia[n];
    find(0, n, sequencia);

    imprimir(0, n, sequencia);
    printf("\n");
    return 0;
}