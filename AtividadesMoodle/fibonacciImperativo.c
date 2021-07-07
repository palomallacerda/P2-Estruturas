#include <stdio.h>

int find(int i, int n,  long long int sequencia[]) 
{
    for (i = 0; i < n; i++) /*n*/
    {
        if (i >= 2) /*1*/
        {
           sequencia[i] = sequencia[i-1]+sequencia[i-2]; /*1*/
        }
        else sequencia[i] = 1; /*1*/
    }

    /*logo teremos que a complexidade será 3n ou n*/
}
int imprimir(int i, int n,  long long int sequencia[])
{
    for (i = 0; i < n; i++) /*n*/
    {
        printf("%lld ", sequencia[i]); /*1*/
    }
    /*logo será complexidade n*/
}
int main()
{   
    int n;
    scanf("%d", &n);
    long long int sequencia[n];
    find(0, n, sequencia);

    imprimir(0, n, sequencia);
    printf("\n");

    /*esse algoritimo terá complexidade n*/
    return 0;
}
