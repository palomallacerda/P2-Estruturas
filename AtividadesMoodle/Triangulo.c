#include <stdio.h>

int find_y(int n, int *y, int i, int sinal, int comeco) /*encontrando o ponto y*/
{
    if (i < n)
    {
        if (i < 1)
        {
           *y = 0;
        }
        else
        {
            if(sinal > 0) /*já passou uma vez pelo positivo*/
            {
                if(comeco > 0)
                {
                    comeco =  0;
                    sinal = 0;
                }
                else
                {
                    *y *= -1;
                    comeco += 1;
                }
            }
            else
            {
                if (*y < 0) /*já passou pelos 2 negativos*/
                {
                    *y *= -1;
                }

                *y += 1;
                sinal += 1;
            }
        }

        find_y(n, y, i+1, sinal, comeco);
    }    
}
int find_x(int n, int *x, int y, int i, int sinal, int igual)
{
    if (i <= n)
    {
        if (n ==  1)
        {
            return  *x = 1;
        }
         
        if (i >= 2)
        {   
           // printf("igual :%d sinal: %d indice:%d\n", igual, sinal, i);
            if (igual > 2)
            {
                *x = y;
                sinal += 1;
                igual = 1;
            }
            else
            {
                if (sinal < 1)
                {
                
                    if (y < 0) y *= -1;
                    *x = i-y;
                   
                    sinal += 1;
                    igual += 1;
                }
                else /*x é negativo*/
                {
                    if (y < 0) y *= -1;
                    *x = i-y;
                    *x *= -1;
                    sinal  = 0;
                    igual += 1;
                }  
            }   
        }
        
        find_x(n, x, y, i+1, sinal, igual);
    }
    
}

int main()
{
    int n, y = 0, x = 0;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("(%d,%d)\n", x, y);
    }
    else 
    {
        find_y(n, &y, 0, 0, 0);
        find_x(n, &x, y, 0, 0, 0);

        printf("(%d,%d)\n", x, y);
    }
   
    return 0;
}
