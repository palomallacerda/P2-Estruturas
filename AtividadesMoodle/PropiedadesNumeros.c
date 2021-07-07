/*faça um programa que recebe um número no formato de string e informa o tipo do número fornecido (natural, inteiros ou real).
Existe a possibilidade do número fornecidos não ser válido para nenhum desses tipos, caso em que uma mensagem de erro deve ser exibida para o usuário*/
#include <stdio.h>
#include <string.h>

int verificar(char numero[100], int size, int i, int natu, int inteiro, int real, int erro, int mais)
{
    if (i <= size)
    {
        if (i == size) /*cond parada*/
        {   
           // printf("real: %d erro: %d inteiro: %d natu: %d mais: %d\n", real, erro, inteiro, natu, mais);
           if (real == 1)
           {
               return printf("É Real\n");
           }
           else if (((real > 1) || (erro > 0)) && ((mais == 0) && (inteiro == 0)))
           {
               return printf("ERRO!\n");   
           }
           else if (inteiro > 0)
           {
             return printf("É Inteiro\n");
           }
           else return printf("É Natural\n");                 
           
        }
        else
        {
          if ((numero[0] == '+') || (numero[0] == '-'))
          { 
              if (numero[0] == '+') /* pode ser natural */
                mais += 1;
              else inteiro += 1;
          }
          if ((numero[i] < '0')  ||  (numero[i] > '9'))
          {
              if (numero[i] == '.' || numero[i] == ',')
                real += 1;
              else erro += 1;
          }        
          else natu += 1;
            return verificar(numero, size, i+1, natu, inteiro, real, erro, mais);
        }
    }
}

int main()
{
    char numero[100]; 
    printf("Digite o número: ");
    scanf("%[^\n]", numero);
    int n = strlen(numero);
    verificar(numero, n, 0, 0, 0, 0, 0, 0);
    return 0;
}
