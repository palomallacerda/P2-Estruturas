#include <stdio.h>

int find(int i, int n, long long int sequencia[]) /*n vzs*/
{
    if (i < n) /*1*/
    {
        if (i >=2 ) /*1*/
        {          
            sequencia[i] = sequencia[i-1]+sequencia[i-2]; /*1*/
        }             
        else sequencia[i] = 1; /*1*/
        find(i+1, n, sequencia); /*4(n)*/
    }   
    /*logo esse programa terá complexidade 4n ou n*/
} 
int imprimir(int i, int n, long long int sequencia[])/*n*/
{
    if (i < n) /*1*/
    {
        printf("%lld ", sequencia[i]); /*1*/
        imprimir(i+1, n, sequencia);
    }

    /*complexidade n*/
}
int main()
{   
    int n;
    scanf("%d", &n);
    long long int sequencia[n];
    find(0, n, sequencia);

    imprimir(0, n, sequencia);
    printf("\n");

    /*logo esse programa terá complexidade n*/
    return 0;
}
