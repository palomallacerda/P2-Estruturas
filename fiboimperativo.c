#include <stdio.h>

int find(int i, int n, int sequencia[])
{
    for (i = 0; i < n; i++)
    {
        if (i >= 2)
        {
           sequencia[i] = sequencia[i-1]+sequencia[i-2];
        }
        else sequencia[i] = 1; 
    }
       
}
int imprimir(int i, int n, int sequencia[])
{
    for (i = 0; i < n; i++)
    {
        printf("%d ", sequencia[i]);
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