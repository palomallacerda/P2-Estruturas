/*faça um programa que receba um nome válido
para efeitos de teste, os nomes válidos são formados só por letra
não existe a possibilidade de um nome ter zero caracteres*/
#include <stdio.h>
#include <string.h>

int imprimir (char nome[60], int tam, int i)
{
    if (i < tam)
    {
        printf("%c", nome[i]);
        imprimir(nome, tam, i+1);
    }
    return 0;     
}
int verificar_numero(char nome[60], int tam, int i, int n_validos)
{
    if (i == tam) /*cond parada*/
    {  
        if (n_validos == (tam-1)) return 1;
        else return 0;
    }
    int valido;
    
    if (i == 0) 
        valido = (nome[0] >= 'A' && nome[0] <= 'Z'); /*valido*/
    else 
        valido = ((nome[i] >= 'A' && nome[i] <= 'Z') || (nome[i] == ' ') || (nome[i] >= 'a' && nome[i] <= 'z')); /*válido*/

    int total = valido + n_validos; 
    return verificar_numero(nome, tam, i+1, total);
}


int ler(char nome[60])
{
    fgets(nome,60,stdin);
    int tam = strlen(nome);
    return tam;
}
int main()
{
    char nome[60];
    int tam = ler(nome); 

    if (tam == 1)
        printf("Não pode ter 0 caracteres\n");
    else
    {
      int valor =  verificar_numero(nome, tam, 0, 0);
     
      if (valor == 1)
        printf("Válido\n");
      else printf("Inválido\n");
       /* imprimir(nome, tam, 0);*/
    }
    
    return 0;
}   
